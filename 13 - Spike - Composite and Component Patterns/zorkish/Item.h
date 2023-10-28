#pragma once
#include <string>

using namespace std;

class Item
{
private:
	string _name;
	string _desc;
	map<string, bool> attributes;  // Attributes of the item.
	vector<string> actions;        // Actions the item can perform.
public:
	Item(const string&, const string&);
	~Item();

	string getName() const;
	string getDesc() const;
	bool hasAttribute(const string& attributeName);
	bool getAttributeState(const string& attributeName);
	void setAttributeState(const string& attributeName, bool state);
	bool canPerformAction(const string& actionName);
};