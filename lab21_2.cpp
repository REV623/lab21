#include<iostream>
using namespace std;

struct Rect{
	double x,y,w,h;
};

double overlap(Rect *R1,Rect *R2){
	double W,H;
	Rect *r1=R1,*r2=R2;
	if((*r1).x>(*r2).x){
		r1=R2;
		r2=R1;
	}

	if(r1->x==r2->x && r1->y==r2->y && r1->w*r1->h<r2->w*r2->h){
		r1=R2;
		r2=R1;
	}

	if((r1->x+r1->w)<r2->x) return 0;

	if(r1->y>=r2->y && (r2->y-r2->h)>=(r1->y-r1->h)) H = r2->h;
	else H = r1->y-(r2->y-r2->h);

	if(r1->x<=r2->x && (r1->x+r1->w)>=(r2->x+r2->w)) W = r2->w;
	else W = r1->x+r1->w-r2->x;

	return W*H;
}

int main(){
	Rect R1 = {1,1,5,5};
	Rect R2 = {2,2,5,5};
	cout << overlap(&R1,&R2);
	return 0;
}