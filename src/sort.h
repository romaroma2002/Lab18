//---------------------------------------------------------------------------



void swap_rows(int row_id1, int row_id2){
        for(int i = 0; i < db.cols_n; i++){
                swap(db.cols[i].values[row_id1], db.cols[i].values[row_id2]);
        }
}



//---------------------------------------------------------------------------



void string_AZ(int col_index){
	for(int i = 0; i < db.rows_n; i++){
                for(int j = i + 1; j < db.rows_n; j++){
                        if(strcmp(db.cols[col_index].values[i].c_str(), db.cols[col_index].values[j].c_str())>0){
                                swap_rows(i, j);
                        }
                }
	}
}


void string_ZA(int col_index){
	for(int i = 0; i < db.rows_n; i++){
                for(int j = i + 1; j < db.rows_n; j++){
                        if(strcmp(db.cols[col_index].values[i].c_str(), db.cols[col_index].values[j].c_str())<0){
                                swap_rows(i, j);
                        }
                }
	}
}



//---------------------------------------------------------------------------



void num_12(int col_index){
       for(int i = 0; i < db.rows_n; i++){
                for(int j = i + 1; j < db.rows_n; j++){
                        if(str_to_double(db.cols[col_index].values[i]) > str_to_double(db.cols[col_index].values[j])){
                                swap_rows(i, j);
                        }
                }
	}
}



void num_21(int col_index){
       for(int i = 0; i < db.rows_n; i++){
                for(int j = i + 1; j < db.rows_n; j++){
                        if(str_to_double(db.cols[col_index].values[i]) < str_to_double(db.cols[col_index].values[j])){
                                swap_rows(i, j);
                        }
                }
	}
}



//---------------------------------------------------------------------------



void bool_tf(int col_index){
       for(int i = 0; i < db.rows_n; i++){
                for(int j = i + 1; j < db.rows_n; j++){
                        if(db.cols[col_index].values[i] == "false" && db.cols[col_index].values[j] == "true"){
                                swap_rows(i, j);
                        }
                }
	}
}



void bool_ft(int col_index){
       for(int i = 0; i < db.rows_n; i++){
                for(int j = i + 1; j < db.rows_n; j++){
                        if(db.cols[col_index].values[i] == "true" && db.cols[col_index].values[j] == "false"){
                                swap_rows(i, j);
                        }
                }
	}
}



//---------------------------------------------------------------------------



void sort_decision(int col_index, string sort){
	if(sort=="Від А до Я")
		string_AZ(col_index);
	else if(sort=="Від Я до А")
		string_ZA(col_index);
	else if(sort=="Зростання")
		num_12(col_index);
	else if(sort=="Спадання")
		num_21(col_index);
	else if(sort=="Спочатку true")
		bool_tf(col_index);
	else if(sort=="Спочатку false")
		bool_ft(col_index);
}
