#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "jpeglib.h"

using namespace std;

void decode_frame(char *filename) {
    unsigned char* raw_image;
    JSAMPROW row_pointer[1];
    unsigned long location = 0;

    struct jpeg_error_mgr jerr;
    struct jpeg_decompress_struct cinfo ;

    FILE *infile = fopen(filename, "rb" );

    if (infile == NULL )
    {
        printf("Error opening jpeg file %s\n!", filename );
        return;
    }
    cinfo.err = jpeg_std_error(&jerr);

    /* create decompressor */
    jpeg_create_decompress(&cinfo);

    /* this makes the library read from infile */
    jpeg_stdio_src(&cinfo, infile );

    /* read jpeg header */
    jpeg_read_header(&cinfo, TRUE);

    /* decompress */
    jpeg_start_decompress(&cinfo);

    /*allocate memory */
    raw_image = (unsigned char*)malloc( cinfo.output_width*cinfo.output_height*cinfo.num_components );

    /* now actually read the jpeg into the raw buffer */
    row_pointer[0] = (unsigned char *)malloc( cinfo.output_width*cinfo.num_components );
    /* read scanlines */
    while (cinfo.output_scanline < cinfo.output_height) {
        jpeg_read_scanlines( &cinfo, row_pointer, 1 );
        for( int i=0; i < cinfo.image_width*cinfo.num_components;i++) 
            raw_image[location++] = row_pointer[0][i];
    }  

    /* clean up */
    jpeg_finish_decompress(&cinfo);
    jpeg_destroy_decompress(&cinfo);
    fclose( infile );
    free( row_pointer[0] );
}

int main(){
    char *f = "example1.jpg";
    decode_frame(f);
    return 0;
}
