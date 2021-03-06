#include "commandfactory.h"
#include <sstream>

// The CommandFactory constructor that takes a CustomerIndex and a
// ProductCollection is used to pass along the two data structures 
// to it's products.
// constructor, inits hash table
CommandFactory::CommandFactory(CustomerIndex* cI, ProductCollection* pC) {
    cIndex = cI;
    pCollect = pC;    
    
    cmds['H'] = new HistoryCMD(cIndex);
    cmds['B'] = new BorrowCMD(cIndex, pCollect);
    cmds['R'] = new ReturnCMD(cIndex, pCollect);
    cmds['S'] = new DisplayAllProductCMD(cIndex, pCollect);
} 

CommandFactory::~CommandFactory(){
    for(it = cmds.begin(); it != cmds.end(); ++it) {
        delete it->second;
    }
} 

// The create method takes in a string and parses out the command portion of the
// string. It then creates an instance of a child command object based on the 
// command it parsed. Finally, it returns a pointer to that command.
Command* CommandFactory::create(std::string data){
    Command* cmd = NULL;
    if(data == ""){
        return cmd;
    }
    std::string cmdString;
    std::string restOfString;
    std::stringstream ss;
    ss << data;
    ss >> cmdString;
    restOfString = ss.str();
    char cmdChar = cmdString.at(0); //Convert string to a char

    if(!keyExists(cmdChar)){
        return cmd;
    }

    cmd = cmds[cmdChar];
    cmd->setData(new Event(restOfString));
    return cmd;    
}

//finds key and returns true if key exists
bool CommandFactory::keyExists(char key){
    it = cmds.find(key);
    if (it == cmds.end()){
        return false;
    }
    else{
        return true;
    }
}

