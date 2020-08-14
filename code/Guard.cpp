#include <bits/stdc++.h>
#include <mysql.h>
#include "Guard.h"

using namespace std;

bool Guard::verifyGuard(string password) {

    MYSQL * conn;
    MYSQL_RES *res;
    MYSQL_ROW row;


    int qstate;
    string query;
    const char* q;
    conn=mysql_init(0);
    conn=mysql_real_connect(conn,"mydbinstance.cs01ubstkjtv.ap-south-1.rds.amazonaws.com","kushwah_1","123456789","newdb",0,NULL,0);
        if(conn){
            query="SELECT * FROM guard WHERE PASSWORD= '"+password+"'";

            q=query.c_str();
            qstate=mysql_query(conn,q );
            if(!qstate){
                        res=mysql_store_result(conn);
                        int x=mysql_num_rows(res);
                        if(x>0){
                                mysql_close(conn);
                            return 1;
                        }
                        else{
                            mysql_close(conn);
                           return 0;
                        }
            }
            else{
                cout<<"\n"<<mysql_error(conn)<<"\n";
                mysql_close(conn);
                return 0;
            }
        }
        else{
             cout<<"\n"<<mysql_error(conn)<<"\n";
             return 0;
        }


}

