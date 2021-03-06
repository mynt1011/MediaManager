#pragma once
#ifndef NODEDATA_H
#define NODEDATA_H
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

/*
NodeData is an abstract class which can be a CustomerData object or a 
ProductData object.

incrProductQuantity() lets the NodeData know that the system has received duplicate data. 
and gives it the duplicate so that it can handle it.
It is not defined in this class, but in the child classes.

getName() returns some unique identifier providing information about the class
of object stored by NodeData.
*/

class NodeData {
    friend std::ostream& operator<<(std::ostream&, const NodeData&);
public:
    NodeData(); // default constructor
    virtual ~NodeData();   // destructor
    NodeData(const NodeData &);    // copy constructor
    NodeData& operator=(const NodeData &);   //assignment operator
    virtual void display(std::ostream&) const = 0;
    // Gives NodeData the duplicate to handle it.
    virtual void incrProductQuantity(NodeData*) = 0;  
    virtual std::string getName() const = 0; // returns unique identifier
    virtual char getKey() const = 0; // returns unique identifier

    // comparison operators
    virtual bool operator==(const NodeData &) const = 0;
    virtual bool operator!=(const NodeData &) const = 0;
    virtual bool operator<(const NodeData &) const = 0;
    virtual bool operator>(const NodeData &) const = 0;
    virtual bool operator<=(const NodeData &) const = 0;
    virtual bool operator>=(const NodeData &) const = 0;                

    virtual std::vector<std::string> getDataTypes() const = 0;      
    virtual int getDataTypeSize() const = 0; // returns size of DataTypes
};

#endif

