#include "utils.h"

//TODO: cleanup the third squareInCircle check

bool Utils::squareInCircle(Point sp, float sw, float sh, Point cp, float cr){
	float sx = sp.getX();
	float sy = sp.getY();
	float cx = cp.getX();
	float cy = cp.getY();

	//check if circle is inside of square
	if ( cx >= sx && cx <= sx + sw && cy >= sy && cy <= sy + sh)
		return true;
		
		
	//check if circle is in one of the sides of the square
	//circle is in top side of square
	if (cy <= sy + cr && cy >= sy - cr && cx >= sx && cx <= sx + sw)
		return true;	
	//circle is in bottom side of square
	if (cy <= sy + sh + cr && cy >= sy + sh - cr && cx >= sx && cx <= sx + sw)
		return true;
	//circle is in left side of square
	if (cx <= sx + cr && cx >= sx - cr && cy >= sy && cy <= sy + sh)
		return true;
	//circle is in right side of square
	if (cx <= sx + sw + cr && cx >= sx + sw - cr && cy >= sy && cy <= sy + sh)
		return true;
		
			
	//check if one of the edges of the square is inside the circle
	//TOP LEFT EDGE OF SQUARE
	float xx1 = (cx - sx) * (cx - sx);
	float yy1 = (cy - sy) * (cy - sy);
	//TOP RIGHT EDGE OF SQUARE
	float xx2 = (cx - (sx + sw)) * (cx - (sx + sw));
	//BOTTOM RIGHT EDGE
	float yy2 = (cy - (sy + sh)) * (cy - (sy + sh));

	//square of circle radius
	float csq = cr * cr;
	
	//square the radius of the circle, because it's faster than square rooting	
	//if the sqaure of the radius is smaller than the square of the distance, the edge of the square is inside of the circle 
	if (csq <= xx1 + yy1 || csq <= xx2 + yy1 || csq <= xx2 + yy2 || csq <= xx1 + yy2) {
		return true;
	}
	
	//if none of the beforehand checks was succesful, the two objects don't collide
	return false;

}


