#include <iostream>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <string>

using namespace std;

namespace pt = boost::property_tree;

pt::ptree tree;

    void AST(const int DetectUnattendedObjects, const int DetermineHumanOrCarObjects, const int DetermineNumOfHumansInGroup, const int DetermineObjectColor, const int DetermineOutliers, const int DetermineUnattendedObjectType, const int MaxObjectHeight, const int MaxObjectWidth, const int MaxUnattendedObjectHeight, const int MaxUnattendedObjectWidth, const int MinObjectHeight, const int MinObjectWidth, const int MinUnattendedObjectHeight, const int MinUnattendedObjectWidth, const int MotionDetectorSensitivity, const int SkipEqualFrames, const int TimeBeforeObjectIsLost, const int UnattendedDetectorSensitivity, const int UseColourInformation ) {
        pt::ptree ASTtree;
        ASTtree.add("DetectUnattendedObjects", DetectUnattendedObjects);
        ASTtree.add("DetermineHumanOrCarObjects", DetermineHumanOrCarObjects);
        ASTtree.add("DetermineNumOfHumansInGroup", DetermineNumOfHumansInGroup);
        ASTtree.add("DetermineObjectColor", DetermineObjectColor);
        ASTtree.add("DetermineOutliers", DetermineOutliers);
        ASTtree.add("DetermineUnattendedObjectType", DetermineUnattendedObjectType);
        ASTtree.add("MaxObjectHeight", MaxObjectHeight);
        ASTtree.add("MaxObjectWidth", MaxObjectWidth);
        ASTtree.add("MaxUnattendedObjectHeight", MaxUnattendedObjectHeight);
        ASTtree.add("MaxUnattendedObjectWidth", MaxUnattendedObjectWidth);
        ASTtree.add("MinObjectHeight", MinObjectHeight);
        ASTtree.add("MinObjectWidth", MinObjectWidth);
        ASTtree.add("MinUnattendedObjectHeight", MinUnattendedObjectHeight);
        ASTtree.add("MinUnattendedObjectWidth", MinUnattendedObjectWidth);
        ASTtree.add("MotionDetectorSensitivity", MotionDetectorSensitivity);
        ASTtree.add("SkipEqualFrames", SkipEqualFrames);
        ASTtree.add("TimeBeforeObjectIsLost", TimeBeforeObjectIsLost);
        ASTtree.add("UnattendedDetectorSensitivity", UnattendedDetectorSensitivity);
        ASTtree.add("UseColourInformation", UseColourInformation);

        tree.add_child("root.AST", ASTtree);
    }
int main()
{
    AST(0,0,0,1,0,0,10000,10000,8000,8000,200,200,200,200,0,0,5,7,1);
    write_xml("result.xml", tree);
}
