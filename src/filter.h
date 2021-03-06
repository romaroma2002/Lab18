#include <math.h>
#include <vector>
struct filter{
	string col_name;
        string dtype;
	string filter_name;
	string value;
} filt;
vector<filter> filter_vector;

//---------------------------------------------------------------------------



int str_to_int(string str){
	int res = 0;
	for(int i = 0; i < str.length(); i++){
		res *= 10;
		res += int(str.c_str()[i]) - 48;
	}
	return res;
}



double str_to_double(string str){
	double res = 0;
	int dot_index = 0;
	for(int i = 0; i < str.length(); i++){
		if(str[i] == '.')
			dot_index = i;
		else{
			res *= 10;
			res += int(str[i]) - 48;
		}	
	}
	return res / pow(10, dot_index);
}



//---------------------------------------------------------------------------



int find_column_index(string col_name){
	for(int i = 0; i < shown_db.cols_n; i++)
		if(db.cols[i].name == col_name)
			return i;
}



//---------------------------------------------------------------------------



void string_equals(int col_index, string value){
	for(int j = 0; j < shown_db.rows_n; j++){
		if(shown_db.cols[col_index].values[j] == value){
			for(int i = 0; i < shown_db.cols_n; i++){
				buf_db.cols[i].values[buf_db.rows_n] = shown_db.cols[i].values[j];
			}
			buf_db.rows_n += 1;
		}
	}
	shown_db = buf_db;
}



void string_not_equals(int col_index, string value){
	for(int j = 0; j < shown_db.rows_n; j++){
		if(shown_db.cols[col_index].values[j] != value){
			for(int i = 0; i < shown_db.cols_n; i++){
				buf_db.cols[i].values[buf_db.rows_n] = shown_db.cols[i].values[j];
			}
			buf_db.rows_n += 1;
		}
	}
	shown_db = buf_db;
}



void string_contains(int col_index, string value){
	for(int j = 0; j < shown_db.rows_n; j++){
		bool contains = false;
		int length = value.length();
		string cell_value = shown_db.cols[col_index].values[j];

		if (cell_value.length() >= length)
		for(int k = 0; k <= cell_value.length() - length; k++)
			if(cell_value.substr(k, length) == value){
				contains = true;
				break;
			}
		
		if(contains){
			for(int i = 0; i < shown_db.cols_n; i++){
				buf_db.cols[i].values[buf_db.rows_n] = shown_db.cols[i].values[j];
			}
			buf_db.rows_n += 1;
		}
	}
	shown_db = buf_db;
}



void string_not_contains(int col_index, string value){
	for(int j = 0; j < shown_db.rows_n; j++){
		bool contains = false;
		int length = value.length();
		string cell_value = shown_db.cols[col_index].values[j];

		if (cell_value.length() >= length)
		for(int k = 0; k <= cell_value.length() - length; k++)
			if(cell_value.substr(k, length) == value){
				contains = true;
				break;
			}
		
		if(!contains){
			for(int i = 0; i < shown_db.cols_n; i++){
				buf_db.cols[i].values[buf_db.rows_n] = shown_db.cols[i].values[j];
			}
			buf_db.rows_n += 1;
		}
	}
	shown_db = buf_db;
}



void string_starts(int col_index, string value){
	for(int j = 0; j < shown_db.rows_n; j++){
		bool starts = false;
		int length = value.length();
		string cell_value = shown_db.cols[col_index].values[j];
		
		if (cell_value.length() >= length)
		if(cell_value.substr(0, length) == value)
			starts = true;
		
		if(starts){
			for(int i = 0; i < shown_db.cols_n; i++){
				buf_db.cols[i].values[buf_db.rows_n] = shown_db.cols[i].values[j];
			}
			buf_db.rows_n += 1;
		}
	}
	shown_db = buf_db;
}



void string_not_starts(int col_index, string value){
	for(int j = 0; j < shown_db.rows_n; j++){
		bool starts = false;
		int length = value.length();
		string cell_value = shown_db.cols[col_index].values[j];
		
		if (cell_value.length() >= length)
		if(cell_value.substr(0, length) == value)
			starts = true;
		
		if(!starts){
			for(int i = 0; i < shown_db.cols_n; i++){
				buf_db.cols[i].values[buf_db.rows_n] = shown_db.cols[i].values[j];
			}
			buf_db.rows_n += 1;
		}
	}
	shown_db = buf_db;
}



void string_ends(int col_index, string value){
	for(int j = 0; j < shown_db.rows_n; j++){
		bool ends = false;
		int length = value.length();
		string cell_value = shown_db.cols[col_index].values[j];

		if (cell_value.length() >= length)
		if(cell_value.substr(cell_value.length() - length, length) == value)
			ends = true;

		if(ends){
			for(int i = 0; i < shown_db.cols_n; i++){
				buf_db.cols[i].values[buf_db.rows_n] = shown_db.cols[i].values[j];
			}
			buf_db.rows_n += 1;
		}
	}
	shown_db = buf_db;
}



void string_not_ends(int col_index, string value){
	for(int j = 0; j < shown_db.rows_n; j++){
		bool ends = false;
		int length = value.length();
		string cell_value = shown_db.cols[col_index].values[j];

		if (cell_value.length() >= length)
		if(cell_value.substr(cell_value.length() - length, length) == value)
			ends = true;

		if(!ends){
			for(int i = 0; i < shown_db.cols_n; i++){
				buf_db.cols[i].values[buf_db.rows_n] = shown_db.cols[i].values[j];
			}
			buf_db.rows_n += 1;
		}
	}
	shown_db = buf_db;
}



//---------------------------------------------------------------------------



void int_equals(int col_index, int value){
	for(int j = 0; j < shown_db.rows_n; j++){
		int cell_value = str_to_int(shown_db.cols[col_index].values[j]);
		if(cell_value == value){
			for(int i = 0; i < shown_db.cols_n; i++){
				buf_db.cols[i].values[buf_db.rows_n] = shown_db.cols[i].values[j];
			}
			buf_db.rows_n += 1;
		}
	}
	shown_db = buf_db;
}



void int_not_equals(int col_index, int value){
	for(int j = 0; j < shown_db.rows_n; j++){
		int cell_value = str_to_int(shown_db.cols[col_index].values[j]);
		if(cell_value != value){
			for(int i = 0; i < shown_db.cols_n; i++){
				buf_db.cols[i].values[buf_db.rows_n] = shown_db.cols[i].values[j];
			}
			buf_db.rows_n += 1;
		}
	}
	shown_db = buf_db;
}



void int_more_than(int col_index, int value){
	for(int j = 0; j < shown_db.rows_n; j++){
		int cell_value = str_to_int(shown_db.cols[col_index].values[j]);
		if(cell_value > value){
			for(int i = 0; i < shown_db.cols_n; i++){
				buf_db.cols[i].values[buf_db.rows_n] = shown_db.cols[i].values[j];
			}
			buf_db.rows_n += 1;
		}
	}
	shown_db = buf_db;
}



void int_more_equals(int col_index, int value){
	for(int j = 0; j < shown_db.rows_n; j++){
		int cell_value = str_to_int(shown_db.cols[col_index].values[j]);
		if(cell_value >= value){
			for(int i = 0; i < shown_db.cols_n; i++){
				buf_db.cols[i].values[buf_db.rows_n] = shown_db.cols[i].values[j];
			}
			buf_db.rows_n += 1;
		}
	}
	shown_db = buf_db;
}



void int_less_than(int col_index, int value){
	for(int j = 0; j < shown_db.rows_n; j++){
		int cell_value = str_to_int(shown_db.cols[col_index].values[j]);
		if(cell_value < value){
			for(int i = 0; i < shown_db.cols_n; i++){
				buf_db.cols[i].values[buf_db.rows_n] = shown_db.cols[i].values[j];
			}
			buf_db.rows_n += 1;
		}
	}
	shown_db = buf_db;
}



void int_less_equals(int col_index, int value){
	for(int j = 0; j < shown_db.rows_n; j++){
		int cell_value = str_to_int(shown_db.cols[col_index].values[j]);
		if(cell_value <= value){
			for(int i = 0; i < shown_db.cols_n; i++){
				buf_db.cols[i].values[buf_db.rows_n] = shown_db.cols[i].values[j];
			}
			buf_db.rows_n += 1;
		}
	}
	shown_db = buf_db;
}



void int_divides(int col_index, int value){
	for(int j = 0; j < shown_db.rows_n; j++){
		int cell_value = str_to_int(shown_db.cols[col_index].values[j]);
		if(cell_value % value == 0){
			for(int i = 0; i < shown_db.cols_n; i++){
				buf_db.cols[i].values[buf_db.rows_n] = shown_db.cols[i].values[j];
			}
			buf_db.rows_n += 1;
		}
	}
	shown_db = buf_db;
}



void int_not_divides(int col_index, int value){
	for(int j = 0; j < shown_db.rows_n; j++){
		int cell_value = str_to_int(shown_db.cols[col_index].values[j]);
		if(cell_value % value != 0){
			for(int i = 0; i < shown_db.cols_n; i++){
				buf_db.cols[i].values[buf_db.rows_n] = shown_db.cols[i].values[j];
			}
			buf_db.rows_n += 1;
		}
	}
	shown_db = buf_db;
}



//---------------------------------------------------------------------------



void double_equals(int col_index, double value){
	for(int j = 0; j < shown_db.rows_n; j++){
		int cell_value = str_to_double(shown_db.cols[col_index].values[j]);
		if(cell_value == value){
			for(int i = 0; i < shown_db.cols_n; i++){
				buf_db.cols[i].values[buf_db.rows_n] = shown_db.cols[i].values[j];
			}
			buf_db.rows_n += 1;
		}
	}
	shown_db = buf_db;
}



void double_not_equals(int col_index, double value){
	for(int j = 0; j < shown_db.rows_n; j++){
		int cell_value = str_to_double(shown_db.cols[col_index].values[j]);
		if(cell_value != value){
			for(int i = 0; i < shown_db.cols_n; i++){
				buf_db.cols[i].values[buf_db.rows_n] = shown_db.cols[i].values[j];
			}
			buf_db.rows_n += 1;
		}
	}
	shown_db = buf_db;
}



void double_more_than(int col_index, double value){
	for(int j = 0; j < shown_db.rows_n; j++){
		int cell_value = str_to_double(shown_db.cols[col_index].values[j]);
		if(cell_value > value){
			for(int i = 0; i < shown_db.cols_n; i++){
				buf_db.cols[i].values[buf_db.rows_n] = shown_db.cols[i].values[j];
			}
			buf_db.rows_n += 1;
		}
	}
	shown_db = buf_db;
}



void double_more_equals(int col_index, double value){
	for(int j = 0; j < shown_db.rows_n; j++){
		int cell_value = str_to_double(shown_db.cols[col_index].values[j]);
		if(cell_value >= value){
			for(int i = 0; i < shown_db.cols_n; i++){
				buf_db.cols[i].values[buf_db.rows_n] = shown_db.cols[i].values[j];
			}
			buf_db.rows_n += 1;
		}
	}
	shown_db = buf_db;
}



void double_less_than(int col_index, double value){
	for(int j = 0; j < shown_db.rows_n; j++){
		int cell_value = str_to_double(shown_db.cols[col_index].values[j]);
		if(cell_value < value){
			for(int i = 0; i < shown_db.cols_n; i++){
				buf_db.cols[i].values[buf_db.rows_n] = shown_db.cols[i].values[j];
			}
			buf_db.rows_n += 1;
		}
	}
	shown_db = buf_db;
}



void double_less_equals(int col_index, double value){
	for(int j = 0; j < shown_db.rows_n; j++){
		int cell_value = str_to_double(shown_db.cols[col_index].values[j]);
		if(cell_value <= value){
			for(int i = 0; i < shown_db.cols_n; i++){
				buf_db.cols[i].values[buf_db.rows_n] = shown_db.cols[i].values[j];
			}
			buf_db.rows_n += 1;
		}
	}
	shown_db = buf_db;
}



//---------------------------------------------------------------------------



void bool_true(int col_index){
	for(int j = 0; j < shown_db.rows_n; j++){
		if(shown_db.cols[col_index].values[j] == "true"){
			for(int i = 0; i < shown_db.cols_n; i++){
				buf_db.cols[i].values[buf_db.rows_n] = shown_db.cols[i].values[j];
			}
			buf_db.rows_n += 1;
		}
	}
	shown_db = buf_db;
}



void bool_false(int col_index){
	for(int j = 0; j < shown_db.rows_n; j++){
		if(shown_db.cols[col_index].values[j] == "false"){
			for(int i = 0; i < shown_db.cols_n; i++){
				buf_db.cols[i].values[buf_db.rows_n] = shown_db.cols[i].values[j];
			}
			buf_db.rows_n += 1;
		}
	}
	shown_db = buf_db;
}



//---------------------------------------------------------------------------



void decicion(filter f){
        string filter_name = f.filter_name;
        string dtype = f.dtype;
        string value = f.value;
	int col_index = find_column_index(f.col_name);
	buf_db.cols_n = shown_db.cols_n;
	for(int i = 0; i < shown_db.cols_n; i++){
		buf_db.cols[i].name = shown_db.cols[i].name;
		buf_db.cols[i].datatype = shown_db.cols[i].datatype;
	}
	buf_db.rows_n = 0;
	if(dtype=="string" && filter_name=="????????")
		string_equals(col_index, value);
	else if(dtype=="string" && filter_name=="?? ????????")
		string_not_equals(col_index, value);
	else if(dtype=="string" && filter_name=="???????")
		string_contains(col_index, value);
	else if(dtype=="string" && filter_name=="?? ???????")
		string_not_contains(col_index, value);
	else if(dtype=="string" && filter_name=="??????????? ??")
		string_starts(col_index, value);
	else if(dtype=="string" && filter_name=="?? ??????????? ??")
		string_not_starts(col_index, value);
	else if(dtype=="string" && filter_name=="???????????? ??")
		string_ends(col_index, value);
	else if(dtype=="string" && filter_name=="?? ???????????? ??")
		string_not_ends(col_index, value);
	else if(dtype=="int" && filter_name=="????????")
		int_equals(col_index, str_to_int(value));
	else if(dtype=="int" && filter_name=="?? ????????")
		int_not_equals(col_index, str_to_int(value));
	else if(dtype=="int" && filter_name=="??????")
		int_more_than(col_index, str_to_int(value));
	else if(dtype=="int" && filter_name=="??????-?????")
		int_more_equals(col_index, str_to_int(value));
	else if(dtype=="int" && filter_name=="?????")
		int_less_than(col_index, str_to_int(value));
	else if(dtype=="int" && filter_name=="?????-?????")
		int_less_equals(col_index, str_to_int(value));
	else if(dtype=="int" && filter_name=="???????? ??")
		int_divides(col_index, str_to_int(value));
	else if(dtype=="int" && filter_name=="?? ???????? ??")
		int_not_divides(col_index, str_to_int(value));
	else if(dtype=="double" && filter_name=="????????")
		double_equals(col_index, str_to_double(value));
	else if(dtype=="double" && filter_name=="?? ????????")
		double_not_equals(col_index, str_to_double(value));
	else if(dtype=="double" && filter_name=="??????")
		double_more_than(col_index, str_to_double(value));
	else if(dtype=="double" && filter_name=="??????-?????")
		double_more_equals(col_index, str_to_double(value));
	else if(dtype=="double" && filter_name=="?????")
		double_less_than(col_index, str_to_double(value));
	else if(dtype=="double" && filter_name=="?????-?????")
		double_less_equals(col_index, str_to_double(value));
	else if(dtype=="bool" && filter_name=="true")
		bool_true(col_index);
	else if(dtype=="bool" && filter_name=="false")
		bool_false(col_index);
}
