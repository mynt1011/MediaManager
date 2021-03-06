#pragma once
#ifndef PRODUCTFACTORY_H
#define PRODUCTFACTORY_H
#include "product.h"
#include "comedy.h"
#include "drama.h"
#include "classic.h"
#include "productcollection.h"
#include <string>

/*
The class ProductFactory collects information about the movie { Classic, 
Drama, Comedy } Once the input has been parsed, this class will fills product 
templates with instances of each instantiatable product object. It will then 
create the product objects , returns null if there is an invalid hash key

*/
class ProductFactory
{
private:
    ProductCollection* pCollect;
    // A pointer to an array of Products implemented as a hash table
    // Product* hashTable; 
    std::map<char, Product*> products;
    std::map<char, Product*>::iterator it;

public:
    //fills producttemplates with instances of each instantiatable 
    //Product object
    ProductFactory(ProductCollection*);    
    virtual ~ProductFactory();
    //parses input to create Product objects, returns null if invalid hash key
    Product* create(std::string key); 		
    bool keyExists(char key);
};

#endif
