#include "stdafx.h"
#include "IShape.h"
#include "Circle.h"

using namespace std;

enum struct ShapeTypeEnum {circle, rectangle, triangle};

map<string, ShapeTypeEnum> shapeTypesMap = { {"circle", ShapeTypeEnum::circle},
								{"rectangle", ShapeTypeEnum::rectangle },
								{"triangle", ShapeTypeEnum::triangle} };

void ReadShapes(vector<shared_ptr<IShape>> shapesVector)
{
	string line;
	while (!cin.eof())
	{
		getline(cin, line);
		stringstream strm(line);
		string sType;
		strm >> sType;
		auto typeIt = shapeTypesMap.find(sType);
		switch (typeIt->second) {
		case ShapeTypeEnum::circle:
			try{
				auto sp = make_shared<CCircle>(CPoint(0, 0), 0, "", "");
				strm >> *sp;
				shapesVector.push_back(sp);
			}
			catch (std::exception e)
			{
				cout << e.what() << endl;
			}
			break;
		case ShapeTypeEnum::rectangle:
			//Read rectangle from stream
			break;
			//Read triangle from stream
		case ShapeTypeEnum::triangle:
			break;
		}
	}
}

int main()
{
	vector<shared_ptr<IShape>> shapes;
	return 0;
}