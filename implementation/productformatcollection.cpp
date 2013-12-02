#include "productformatcollection.h"

/*
ProductFormatCollection::FormatAmount::~FormatAmount(){
	if(format != NULL){
		delete format;
		format = NULL;
	}
}
*/

ProductFormatCollection::~ProductFormatCollection(){
	for (std::list<FormatAmount>::iterator
		it=formatDataList.begin(); 
		it != formatDataList.end(); ++it){
		FormatAmount& fa = *it;
		delete fa.format;
		fa.format = NULL;
	}
}

int ProductFormatCollection::getFormatAmount(const ProductFormat& pf) const{
	std::string searchName = pf.getName();
	for (std::list<FormatAmount>::const_iterator 
		it=formatDataList.begin(); 
		it != formatDataList.end(); ++it){
		if(it -> format -> getName() == searchName){
			return it -> count;
		}
	}
	return 0;
}
	
int ProductFormatCollection::getFormatMaxAmount(const ProductFormat& pf) const{
	std::string searchName = pf.getName();
	for (std::list<FormatAmount>::const_iterator 
		it=formatDataList.begin(); 
		it != formatDataList.end(); ++it){
		if(it -> format -> getName() == searchName){
			return it -> size;
		}
	}
	return 0;
}

bool ProductFormatCollection::addProductFormat(ProductFormat* pf){
	std::string searchName = pf -> getName();
	std::list<FormatAmount>::iterator it = formatDataList.begin();
	while(it != formatDataList.end()){
		if(it -> format -> getName() == searchName){
			FormatAmount& fa = *it;
			int amount = DEFAULT_PRODUCT_QUANTITY;
			addAmount(fa, amount);
			return true;	//TODO: maybe return false if not valid?
		}
		++it;
	} 
	FormatAmount inserted;
	inserted.size = inserted.count = DEFAULT_PRODUCT_QUANTITY;
	inserted.format = pf;
	formatDataList.insert(it, inserted);
	return true;
}

void ProductFormatCollection::duplicate(std::string searchName){
	std::list<FormatAmount>::iterator it=formatDataList.begin();
	while(it != formatDataList.end()){
		if(it -> format -> getName() == searchName){
			FormatAmount& fa = *it;
			int amount = DEFAULT_PRODUCT_QUANTITY;
			addAmount(fa, amount);
			return;
		}
		++it;
	} 
}

void ProductFormatCollection::addAmount(FormatAmount& format, int amount){
	format.size += amount;
	format.count += amount;
}

const void ProductFormatCollection::display(std::ostream& output) const{	//display the amount of each format. NOTE: might be wrong way to do this
	for (std::list<FormatAmount>::const_iterator 
		it=formatDataList.begin(); 
		it != formatDataList.end(); ++it){
		if(it -> size != 0){
			ProductFormat* nextFormat = (it -> format);
			output << nextFormat -> getName() << ": " << it -> count << " ";
		}
	}
	output << std::endl;
}