struct coordinates{
        int col;
        int row;
};

extern struct coordinates crds;

bool search_equals(int start_row, int start_col, string value){
        for(int j = 0; j < shown_db.rows_n; j++){
                for(int i = 0; i < shown_db.cols_n; i++){
                        int p1 = j * shown_db.cols_n + i;
                        int p2 = start_row * shown_db.cols_n + start_col;
                        if(p1 >= p2 && shown_db.cols[i].values[j] == value){
                                crds.col = i;
                                crds.row = j;
                                return true;
                        }
                }
        }
        return false;
}

bool search_contains(int start_row, int start_col, string value){
        for(int j = 0; j < shown_db.rows_n; j++){
                for(int i = 0; i < shown_db.cols_n; i++){
		        int length = value.length();
		        string cell_value = shown_db.cols[i].values[j];

                        int p1 = j * shown_db.cols_n + i;
                        int p2 = start_row * shown_db.cols_n + start_col;

		        if (cell_value.length() >= length)
                        for(int k = 0; k <= cell_value.length() - length; k++)
			        if(p1 >= p2 && cell_value.substr(k, length) == value){
                                crds.col = i;
                                crds.row = j;
                                return true;
			        }
                }
        }
        return false;
}

bool search_starts(int start_row, int start_col, string value){
        for(int j = 0; j < shown_db.rows_n; j++){
                for(int i = 0; i < shown_db.cols_n; i++){
		        int length = value.length();
		        string cell_value = shown_db.cols[i].values[j];

                        int p1 = j * shown_db.cols_n + i;
                        int p2 = start_row * shown_db.cols_n + start_col;
                        
		        if (cell_value.length() >= length)
                        if(p1 >= p2 && cell_value.substr(0, length) == value){
                        crds.col = i;
                        crds.row = j;
                        return true;
                        }
                }
        }
        return false;
}

bool search_ends(int start_row, int start_col, string value){
        for(int j = 0; j < shown_db.rows_n; j++){
                for(int i = 0; i < shown_db.cols_n; i++){
		        int length = value.length();
		        string cell_value = shown_db.cols[i].values[j];

                        int p1 = j * shown_db.cols_n + i;
                        int p2 = start_row * shown_db.cols_n + start_col;
                        
		        if (cell_value.length() >= length)
		        if(p1 >= p2 && cell_value.substr(cell_value.length() - length, length) == value){
                        crds.col = i;
                        crds.row = j;
                        return true;
                        }
                }
        }
        return false;
}
