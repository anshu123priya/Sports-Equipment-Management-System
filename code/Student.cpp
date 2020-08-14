#pragma once
#include<bits/stdc++.h>
#include "Student.h"
//#include <winsock.h>
#include <mysql.h>
#include <ctime>

using namespace std;

bool Student::matchDetailsStudent(string userName, string password) {
    MYSQL * conn;
    MYSQL_RES* res;
    MYSQL_ROW row;
    int qstate;
    string query;
    const char* q;
    conn=mysql_init(0);
    conn=mysql_real_connect(conn,"mydbinstance.cs01ubstkjtv.ap-south-1.rds.amazonaws.com","kushwah_1","123456789","newdb",0,NULL,0);
            if(conn){
                    query="SELECT * FROM studenttable WHERE USERNAME= '"+userName+"' AND PAASSWORD = '"+password+"'";

                    q=query.c_str();
                    qstate=mysql_query(conn,q );

                    if(!qstate){
                                res=mysql_store_result(conn);
                                if(mysql_num_rows(res)){
                                    row=mysql_fetch_row(res);
                                    this->name=row[0];
                                    this->roll=row[1];
                                    this->userName=row[2];
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
            }
    }

string Student::getName() {

    return this->name;
}

string Student::getRoll() {

    return this->roll;
}

string Student::getUserName() {

    return this->userName;

}

double Student::getDues() {

    MYSQL * conn;
    MYSQL_RES *res;
    MYSQL_ROW row;


    int qstate;
    string query;
    const char* q;
    conn=mysql_init(0);
    conn=mysql_real_connect(conn,"mydbinstance.cs01ubstkjtv.ap-south-1.rds.amazonaws.com","kushwah_1","123456789","newdb",0,NULL,0);
        if(conn){
                query="SELECT * FROM studenttable WHERE ROLL='"+this->getRoll()+"'";
                q=query.c_str();
                qstate=mysql_query(conn,q );
                       if(!qstate){
                            res=mysql_store_result(conn);
                            int x=mysql_num_rows(res);
                            if(x>0){
                                row=mysql_fetch_row(res);
                                string currDues=row[4];
                                int  ans=0;
                                for(int i=0;i<currDues.size();i++){
                                    ans*=10;
                                    ans+=currDues[i]-'0';

                                }
                                mysql_close(conn);
                                return ans;
                            }
                            else{
                                    mysql_close(conn);
                                return 0;
                            }
                       }
                       else{
                        cout<<"\n"<<mysql_error(conn)<<"\n";
                        mysql_close(conn);
                        return -1;
                       }
        }
        else{
            cout<<"\n"<<mysql_error(conn)<<"\n";
            return -1;
        }
}


void Student::clearDues(double val) {

    MYSQL * conn;
    MYSQL_RES *res;
    MYSQL_ROW row;


    int qstate;
    string query;
    const char* q;
    conn=mysql_init(0);
    conn=mysql_real_connect(conn,"mydbinstance.cs01ubstkjtv.ap-south-1.rds.amazonaws.com","kushwah_1","123456789","newdb",0,NULL,0);

        if(conn){
                int curr_dues=this->getDues();
                int newDues=curr_dues-val;

                string  vals="";
                while(newDues){
                    vals+=(newDues%10)+'0';
                    newDues/=10;

                }
                reverse(vals.begin(),vals.end());

                query="UPDATE studenttable SET DUES= '"+ vals +"' WHERE NAME= '"+this->name+"' AND ROLL = '"+this->roll+"'";
                q=query.c_str();
                qstate=mysql_query(conn,q );
                if(!qstate){

                }
                else{
                    cout<<"\n"<<mysql_error(conn)<<"\n";
                }

                mysql_close(conn);
            }
            else{
                cout<<"\n"<<mysql_error(conn)<<"\n";
            }
}

bool Student::matchDetailsSecretary(string userName, string password) {
    MYSQL * conn;
    MYSQL_RES* res;
    MYSQL_ROW row;
    int qstate;
    string query;
    const char* q;
    conn=mysql_init(0);
    conn=mysql_real_connect(conn,"mydbinstance.cs01ubstkjtv.ap-south-1.rds.amazonaws.com","kushwah_1","123456789","newdb",0,NULL,0);
        if(conn){
                    query="SELECT * FROM studenttable WHERE USERNAME= '"+userName+"' AND PAASSWORD = '"+password+"' AND ISSECRETARY =1";

                    q=query.c_str();
                    qstate=mysql_query(conn,q );

                    if(!qstate){

                            res=mysql_store_result(conn);
                            if(mysql_num_rows(res)){
                                row=mysql_fetch_row(res);
                                this->name=row[0];
                                this->roll=row[1];
                                this->userName=row[2];
                                mysql_close(conn);
                                return 1;
                            }
                            else{
                                cout<<"Details Can't be matched\n ";
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


void Student::addDues(double due) {

    MYSQL * conn;
    MYSQL_RES* res;
    MYSQL_ROW row;
    int qstate;
    string query;
    string  val;

    const char* q;
    conn=mysql_init(0);
     conn=mysql_real_connect(conn,"mydbinstance.cs01ubstkjtv.ap-south-1.rds.amazonaws.com","kushwah_1","123456789","newdb",0,NULL,0);
     if(conn){

        int dues=this->getDues();
        dues+=due;

        while(dues){
            val+=(dues%10)+'0';
            dues/=10;
        }
            reverse(val.begin(),val.end());


            query="UPDATE studenttable SET DUES= '"+ val +"' WHERE NAME= '"+this->name+"' AND ROLL = '"+this->roll+"'";

            q=query.c_str();
            qstate=mysql_query(conn,q );
            if(!qstate){

            }
            else{
                cout<<"\n"<<mysql_error(conn)<<"\n";
            }


            mysql_close(conn);
         }
     else{
        cout<<"\n"<<mysql_error(conn)<<"\n";
     }
}

bool Student::getDetailsByRoll(string roll) {

    MYSQL * conn;
    MYSQL_RES* res;
    MYSQL_ROW row;
    int qstate;
    string query;
    string  val;

    const char* q;
    conn=mysql_init(0);
    conn=mysql_real_connect(conn,"mydbinstance.cs01ubstkjtv.ap-south-1.rds.amazonaws.com","kushwah_1","123456789","newdb",0,NULL,0);

    if(conn){
    query="SELECT * FROM studenttable WHERE ROLL= '" +roll +"'";
    q=query.c_str();
 	qstate=mysql_query(conn,q );
        if(!qstate){
           
            res=mysql_store_result(conn);

                if(mysql_num_rows(res)>0){

                    row=mysql_fetch_row(res);
                    this->name=row[0];
                    this->roll=row[1];
                    this->userName=row[2];

                    mysql_close(conn);

                    return 1;
                }
                else{
                    mysql_close(conn);
                    return 0;
                }

        }
        else{
            return 0;
        }
    }
    else{
        return 0;
    }


}


