#include <iostream>

using namespace std;

class Builder;

class NutritionFacts {
    // Parameters initialized to default values (if any)
    private:
       int servingSize; // Required
       int servings;  // Required
       int calories;  // Optional
       int fat;  // Optional
       int sodium;  // Optional
       int carbohydrate;  // Optional

    public:
       // Constructor
       NutritionFacts(int servingSize, int servings) { 
          this->servingSize= servingSize;
          this->servings= servings; 
          this->calories = 0;
          this->fat = 0;
          this->sodium = 0;
          this->carbohydrate = 0;
       }
       NutritionFacts(Builder& builder) ;
       // Setters
       void setServingSize(int val) { servingSize = val; }
       void setServings(int val) { servings = val; }
       void setCalories(int val) { calories = val; }
       void setFat(int val) { fat = val; }
       void setSodium(int val) { sodium = val; }
       void setCarbohydrate(int val) { carbohydrate = val; }
       friend ostream& operator<<(ostream&, const NutritionFacts&);
};

class Builder  {
    // Parameters initialized to default values (if any)
    private:
       int _servingSize; // Required
       int _servings;  // Required
       int _calories;  // Optional
       int _fat;  // Optional
       int _sodium;  // Optional
       int _carbohydrate;  // Optional

     public:
        friend class NutritionFacts;
        Builder(int servingSize, int servings) {
            _servingSize = servingSize;
            _servings    = servings;
        }
        Builder& calories(int val) { 
           _calories = val;      
           return *this; 
        }
        Builder& fat(int val) { 
           _fat = val;           
           return *this; 
        }
        Builder& carbohydrate(int val) { 
           _carbohydrate = val;  
           return *this; 
        }
        Builder sodium(int val) { 
           _sodium = val; 
           return *this; 
        }
        NutritionFacts* build() {
            return new NutritionFacts(*this);
        }
};

ostream& operator<<(ostream& out, const NutritionFacts& nf){
	out << "NutritionFacts [ " 
            << "servingSize= " << nf.servingSize << ", "
            << "servings= " << nf.servings << ", "
            << "calories= " << nf.calories << ", "
            << "fat= " << nf.fat << ", "
            << "sodium= " << nf.sodium << ", "
            << "carbohydrate= " << nf.carbohydrate 
            << " ]" << endl;
        return out; 
}

NutritionFacts::NutritionFacts(Builder& builder){
   servingSize  = builder._servingSize;
   servings     = builder._servings;
   calories     = builder._calories;
   fat          = builder._fat;
   sodium       = builder._sodium;
   carbohydrate = builder._carbohydrate;
}

int main(){
	NutritionFacts cocaCola(240,8);
	cocaCola.setCalories(100);
	cocaCola.setSodium(35);
	cocaCola.setCarbohydrate(27);
        cout << cocaCola;
        NutritionFacts *pColaTurka=   
                 Builder(243,8).calories(108)
                               .sodium(36)
                               .carbohydrate(23)
                 .build();
        NutritionFacts& colaTurka= *pColaTurka;
        cout << colaTurka ;                                     
        
        return 0; 
}
