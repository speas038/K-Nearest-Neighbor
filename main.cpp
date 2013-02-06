/*
 * main.cpp
 *
 *  Created on: Feb 4, 2013
 *      Author: Alex
 *
 *
 *
 *      integer values are ordinal
 *
 *      decimal values are continuous
 *
 *      all else is categorical (distance of 1 or 0)
 *
 *
 */


#include<iostream>
#include<fstream>
#include<string>
#include<cmath>

using namespace std;

double find_distance(string,string);
double sub_distance(string,string);
int isint(string);


int main()
{
	ifstream fin;
	ofstream fout;

	string temp_instance = "initialize";
	string instances[10000];
	string input;

	int rows = 0;
	int num_attrubutes = 0;
	int test_size;
	int training_size;


	fin.open("credit-g.arff");

	int j = -1;
	while(j == -1){
		getline(fin, temp_instance, '\n');
		j = temp_instance.find("@data");
		num_attrubutes++;
	}

//Populate array (data has already been randomized
	while (!fin.eof()){
		getline(fin, instances[rows], '\n');
		cout << "instances[" << rows << "] = " << instances[rows] << endl;
		rows++;
	}

	test_size = rows/10;
	training_size = rows - test_size;


	fin.close();

}


double find_distance(string instance, string compare)
{

	string instance_sub, compare_sub;
	int pos1 = 0, pos2 = 0;
	int prev_pos1 = 0, prev_pos2 = 0;
	double dist = 0.0;

	while ( pos1 != -1 && pos2 != -1){

			pos1 = -1;
			pos2 = -1;

			pos1 = instance.find(',', prev_pos1 + 1);
			pos2 = compare.find(',', prev_pos2 + 1);

			instance_sub = instance.substr(prev_pos1 + 1, pos1 - (prev_pos1 + 1));
			compare_sub = compare.substr(prev_pos2 + 1, pos2 - (prev_pos2 + 1));

			dist += sub_distance(instance_sub, compare_sub);

//			cout << "dist value:" << dist << " instance_sub: " << instance_sub <<" compare_sub: " << compare_sub <<  endl;






//fcomdfsdkksdfksdf
			prev_pos1 = pos1;
			prev_pos2 = pos2;

	}

	return dist;
}


double sub_distance(string instance_sub, string compare_sub)
{

	double num1 = 0.0;
	double num2 = 0.0;
	double result = 0.0;

//For nominal data
	if( !isdigit(instance_sub[0]) && !isdigit(compare_sub[0]) ){

		//if they are not equal they are 1 apart
		if(instance_sub != compare_sub){
//			cout << "\n Instance_sub: " << instance_sub << "compare_sub: " << compare_sub << endl;
			return 1;
		}else{
			return 0;
		}
	}

	if(isdigit(instance_sub[0]) && isdigit(compare_sub[0])){
		num1 = strtod(instance_sub.c_str(), NULL);
		num2 = strtod(compare_sub.c_str(), NULL);
		result = abs( (num1 - num2 ) );
		if (result > 1)
			result = 1;
//		cout << endl << "comparing doubles: " << num1 << " and " <<num2 << endl;
//		cout << "result: " << result << endl;
		return result;
	}
}



