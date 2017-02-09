#include "stdafx.h"
#include "IShape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"

using namespace std;

enum struct ShapeTypeEnum {circle, rectangle, triangle};

map<string, ShapeTypeEnum> shapeTypesMap = { {"circle", ShapeTypeEnum::circle},
								{"rectangle", ShapeTypeEnum::rectangle },
								{"triangle", ShapeTypeEnum::triangle} };

void ReadShapes(vector<shared_ptr<IShape>> & shapesVector, istream & in)
{
	string line;
	while (!in.eof())
	{
		getline(in, line);
		if (in.eof())
		{
			break;
		}
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
			break;
			//Read triangle from stream
		case ShapeTypeEnum::triangle:
			try {
				auto sp = make_shared<CTriangle>(CPoint(0, 0),
					CPoint(0, 0), CPoint(0, 0), "", "");
				strm >> *sp;
				shapesVector.push_back(sp);
			}
			catch (std::exception e)
			{
				cout << e.what() << endl;
			}
			break;
		}
	}
}

void PrintShapes(ostream & out, vector<shared_ptr<IShape>> const &shapes)
{
	if (shapes.size() > 0)
	{
		for (auto pShape : shapes)
		{
			out << pShape->ToString() << endl;
		}
	}
	else
	{
		out << "Shapes vector empty!" << endl;
	}
}

int main()
{
	vector<shared_ptr<IShape>> shapes;
	ReadShapes(shapes, cin);
	PrintShapes(cout, shapes);
	return 0;
}