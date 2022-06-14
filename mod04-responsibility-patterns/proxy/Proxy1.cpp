#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "jpeglib.h"

using namespace std;

class RealImage {
    void decode(const char *filename) {
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
    const char *filename;
  public:
    RealImage(const char *filename){
        this->filename = filename;
        decode(filename);	
        cout << "Constructoring the real image for the file " << filename << '\n';
    }
    ~RealImage(){
        cout << "Destructoring the real image for the file " << filename << '\n';    
    }
    void draw() {
        cout << "Drawing image " << filename << '\n';
    }
};

// 1. Design an "extra level of indirection" wrapper class
class Image {
    // 2. The wrapper class holds a pointer to the real class
    RealImage *m_the_real_thing;
    const char *filename;
  public:
    Image(const char *filename) {
        cout << "Constructoring the proxy image for the file " << filename << '\n';
	m_the_real_thing= 0L;
        this->filename= filename;
    }
    ~Image() {
        delete m_the_real_thing;
    }
    void draw() {
        // 4. When a request comes in, the real object is
        //    created "on first use"
        if (!m_the_real_thing)
          m_the_real_thing = new RealImage(filename);
        m_the_real_thing->draw();
    }
};

int main() {
  Image *images[5];
  images[0] = new Image("example1.jpg");
  images[1] = new Image("example2.jpg");
  images[2] = new Image("example3.jpg");
  images[3] = new Image("example4.jpg");
  images[4] = new Image("example5.jpg");

  for (int i=0;i<5;i+=2) {
      images[i]->draw();	
  }
}
