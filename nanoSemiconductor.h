
#include <iostream>
#include <fstream>
#include <vector>
#include <string>


class nanoSemiconductor{

	public:
		nanoSemiconductor(double arg_dx ,double arg_dy ,double arg_dz ,
 				  int arg_nx ,int arg_ny ,int arg_nz ,int arg_nz1 ,int arg_nz2 ,int arg_iter ,int arg_itp,
				  double arg_nx1,double arg_nx2,double arg_nx3,double arg_nx4,double arg_nx5,double arg_nx6,double arg_nx7,double arg_nx8,double arg_nx9,double arg_nx10,double arg_nx11,double arg_nx12,
				  double arg_ny1,double arg_ny2,double arg_ny3,double arg_ny4,double arg_ny5,double arg_ny6,double arg_ny7,double arg_ny8,double arg_ny9,double arg_ny10,double arg_ny11,double arg_ny12,
				  double arg_v0 , double arg_v1 , double arg_v2 , double arg_v3 , double arg_v4 , double arg_v5 , double arg_v6);
		~nanoSemiconductor();
		void simulate();
		void save(std::string,std::string,std::string);

	private:

		double dx,dy,dz; //8
		int nx,ny,nz,nz1,nz2;
		int iter,itp; //2
		double nx1,nx2,nx3,nx4,nx5,nx6,nx7,nx8,nx9,nx10,nx11,nx12; //12
		double ny1,ny2,ny3,ny4,ny5,ny6,ny7,ny8,ny9,ny10,ny11,ny12;//12
		double v0,v1,v2,v3,v4,v5,v6; //7

		double ***vtot, ***vtot1; //dane
		int idxNum;
		void Poisson();
		int *vecPot;
};




