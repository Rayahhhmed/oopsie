
// Cues to use this:
// You have items that you need to create. They are SEPARATE distinct 
// items. If they have simillarities, use Abstract Factory. 
//

#include <iostream>
#include <string>


class Product { 
  public:
    virtual ~Product() {}
    virtual std::string Operation() const = 0;
};


class Airpods: public Product { 
  public: 
    std::string Operation() const override { 
      return "Airpods\n";
    }
};

class Mac: public Product { 
  public: 
    std::string Operation() const override { 
      return "Mac\n";
    }

};


class Factory { 
  public:
    virtual ~Factory() {};
    virtual Product *FactoryMethod() const = 0;

  std::string createItem() const { 
    // Call the Concrete Factory to create the product.
    Product *product = this->FactoryMethod();
    std::string res = "I have created: " + product->Operation();
    delete product;
    return res;
  }
  
};


class AirpodsFactory: public Factory { 
  public: 
  Product* FactoryMethod() const override { 
    return new Airpods();
  }
};

class MacFactory: public Factory { 
  public: 
  
  Product* FactoryMethod() const override { 
    return new Mac();

  } 

};




int main () { 
  
  return 0;
}
