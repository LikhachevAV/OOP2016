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
			break;
		case ShapeTypeEnum::rectangle:
			break;
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