#pragma once
#include <bits/stdc++.h>
#include <mysql.h>
#include <ctime>
#include "OutstandingEquipments.h"
#include "Student.h"
//#include "Student.cpp"

using namespace std;

bool OutstandingEquipments::removeOutStanding(string equipments, Student student) {

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
                query="SELECT * FROM outstandingequipments WHERE ROLL_NUMBER='"+student.getRoll()+"' AND EQUIPMENT_CATEGORY= '"+equipments+"'";
                q=query.c_str();
                qstate=mysql_query(conn,q);
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
                            mysql_close(conn);
                            return 0;
                        }
        }
        else{
            cout<<"\n"<<mysql_error(conn)<<"\n";
            return 0;
        }


}



void OutstandingEquipments::addToOutStandingData(vector<string> equipments, vector<string> equipmentId, Student student,
                                                 vector<string> date) {
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
                for(int i=0;i<equipmentId.size();i++){
                    query="INSERT INTO outstandingequipments ( EQUIPMENT_CATEGORY,EQUIPMENT_ID,STUDENT_NAME,ROLL_NUMBER,ISSUE_DATE,RETURN_DATE) VALUES('"+equipments[i]+"','"+equipmentId[i]+"','"+student.getName()+"','"+student.getRoll()+"','"+date[i]+"','"+returnDate(date[i])+"')";
                    q=query.c_str();
                    qstate=mysql_query(conn,q);
                }
                mysql_close(conn);
        }
        else{
            cout<<"\n"<<mysql_error(conn)<<"\n";
        }
}

void OutstandingEquipments::getListOfOtstanding(string & equipment, vector<string>& equipmentId, vector<string>& roll,
                                                vector<string>& issueDate, vector<string>& returnDate) {


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
                query="SELECT * FROM outstandingequipments WHERE EQUIPMENT_CATEGORY='"+equipment+"'";
                q=query.c_str();
                qstate=mysql_query(conn,q);
                if(!qstate){
                            res=mysql_store_result(conn);
                            int x=mysql_num_rows(res);

                            while(x--){
                                row=mysql_fetch_row(res);
                                equipmentId.push_back(row[1]);
                                roll.push_back(row[3]);
                                issueDate.push_back(row[4]);
                                returnDate.push_back(row[5]);
                            }
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

void OutstandingEquipments::removeFromOutStanding(vector<string> equipmentId) {


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
            for(int i=0;i<equipmentId.size();i++){
                query="DELETE FROM outstandingequipments WHERE EQUIPMENT_ID='"+equipmentId[i]+"'";

                q=query.c_str();
                qstate=mysql_query(conn,q);
                if(qstate){
                        cout<<"\n"<<mysql_error(conn)<<"\n";
                    break;
                }
            }
             mysql_close(conn);
     }
     else{
        cout<<"\n"<<mysql_error(conn)<<"\n";
     }
}

void OutstandingEquipments::getCompleteList(vector<string> &equipments, vector<string> &equipmentId, vector<string> &roll,
                                            vector<string> &issueDate, vector<string> &returnDate) {

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
                    query="SELECT * FROM outstandingequipments ";

                     q=query.c_str();
                     qstate=mysql_query(conn,q);
                     if(!qstate){
                                 res=mysql_store_result(conn);
                                 int x=mysql_num_rows(res);
                                 while(x--){
                                    row=mysql_fetch_row(res);
                                    equipments.push_back(row[0]);
                                    equipmentId.push_back(row[1]);
                                    roll.push_back(row[3]);
                                    issueDate.push_back(row[4]);
                                    returnDate.push_back(row[5]);
                                 }
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

string  OutstandingEquipments::getTodayDate() {

      time_t now = time(0);
      tm *ltm = localtime(&now);

       int y=1900+(ltm->tm_year);
       int m=1+(ltm->tm_mon);
       int d=(ltm->tm_mday);

    return toString(y)+"-"+toString(m)+"-"+toString(d);

}


int OutstandingEquipments::issuedByStudent(Student student){

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
                query="SELECT * FROM outstandingequipments WHERE ROLL_NUMBER='" +student.getRoll()+"'";

                 q=query.c_str();
                 qstate=mysql_query(conn,q);
                    if(!qstate){
                             res=mysql_store_result(conn);
                             if(mysql_num_rows(res)>0){int x=mysql_num_rows(res);
                             mysql_close(conn);
                                return x;
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
 int OutstandingEquipments::to_integer(string s){
                int sum=0;
                for(int i=0;i<s.size();i++){
                    sum*=10;
                    sum+=s[i]-'0';
                }
                return sum;
              }





string OutstandingEquipments::toString(int x){
    int t=x;
    string s="";
    while(x){
    s+='0'+(x%10);
        x/=10;
        }
    if(t<10){string t="0";t+=s;
            return t;
        }
    reverse(s.begin(),s.end());
        return s;
    }


string OutstandingEquipments::returnDate(string date){
                         int y=to_integer(date.substr(0,4));
                         int m=to_integer(date.substr(5,2));
                         int d=to_integer(date.substr(8,2));


                            tm t = {};
                            t.tm_year = y-1900;
                            t.tm_mon  = m-1;
                            t.tm_mday = d;

                            t.tm_mday += 2;
                            mktime(&t);

                            string ans="" ;
                            ans+=toString(t.tm_year+1900);
                            ans+='-';
                            ans+=toString(1+t.tm_mon);
                            ans+='-';
                            ans+=toString(t.tm_mday);
                        return ans;
    }

string OutstandingEquipments::getId(string equipmentCategory, Student student){
    MYSQL * conn;
    MYSQL_RES* res;
    MYSQL_ROW row;
    int qstate;
    string query;
    string  val;

    const char* q;
    conn=mysql_init(0);
    if(conn){
                 conn=mysql_real_connect(conn,"mydbinstance.cs01ubstkjtv.ap-south-1.rds.amazonaws.com","kushwah_1","123456789","newdb",0,NULL,0);

                query="SELECT * FROM outstandingequipments WHERE ROLL_NUMBER='" +student.getRoll()+"' AND EQUIPMENT_CATEGORY='"+equipmentCategory+"'";

                 q=query.c_str();
                 qstate=mysql_query(conn,q);
                    if(!qstate){
                             res=mysql_store_result(conn);

                              int x=mysql_num_rows(res);
                              if(x>0){
                                row=mysql_fetch_row(res);
                                string x=row[1];
                                mysql_close(conn);
                                return x;
                              }
                              else{
                                    mysql_close(conn);
                                return NULL;
                              }
                    }
                    else{
                        cout<<"\n"<<mysql_error(conn)<<"\n";
                        mysql_close(conn);
                        return NULL;
                    }
            }
            else{
                cout<<"\n"<<mysql_error(conn)<<"\n";
                return NULL;
            }

      }

int OutstandingEquipments::additionalDays(string equipmentId){

    string today=getTodayDate();
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
                query="SELECT * FROM outstandingequipments WHERE EQUIPMENT_ID='" +equipmentId+"'";
                 q=query.c_str();
                 qstate=mysql_query(conn,q);
                        if(!qstate){
                                     res=mysql_store_result(conn);
                                     int x=mysql_num_rows(res);
                                     if(x>0){
                                            row=mysql_fetch_row(res);
                                            string date=row[4];
                                            int count=0;
                                            string ans=date.substr(0,10) ;
                                            while(ans!=today){
                                                         int y=to_integer(date.substr(0,4));
                                                         int m=to_integer(date.substr(5,2));
                                                         int d=to_integer(date.substr(8,2));
                                                            tm t = {};
                                                            t.tm_year = y-1900;
                                                            t.tm_mon  = m-1;
                                                            t.tm_mday = d;
                                                            t.tm_mday += 1;
                                                            mktime(&t);
                                                            ans=toString(t.tm_year+1900);
                                                            ans+='-';
                                                            ans+=toString(1+t.tm_mon);
                                                            ans+='-';
                                                            ans+=toString(t.tm_mday);
                                                            date=ans;
                                                            count++;
                                            }
                                            mysql_close(conn);
                                        if(count>2){return count-2;}
                                        else{return 0;}
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
