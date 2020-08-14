#include <bits/stdc++.h>
#include <mysql.h>
#include "AvailableEquipments.h"
#include "Student.h"

using namespace std;

void AvailableEquipments::removeFromData(vector<string> equipmentsId) {
    MYSQL * conn;
    MYSQL_RES* res;
    MYSQL_ROW row;
    int qstate;
    string query;
    const char* q;
    conn=mysql_init(0);
     conn=mysql_real_connect(conn,"mydbinstance.cs01ubstkjtv.ap-south-1.rds.amazonaws.com","kushwah_1","123456789","newdb",0,NULL,0);
         if(conn){
                for(int i=0;i<equipmentsId.size();i++){
                    query="DELETE FROM availableequipments WHERE EQUIPMENT_ID= '"+equipmentsId[i]+"'";
                    q=query.c_str();
                    qstate=mysql_query(conn,q );
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

int AvailableEquipments::equipmentAvailable(string equipment) {
    MYSQL * conn;
    MYSQL_RES* res;
    MYSQL_ROW row;
    int qstate;
    string query;
    const char* q;
    conn=mysql_init(0);
     conn=mysql_real_connect(conn,"mydbinstance.cs01ubstkjtv.ap-south-1.rds.amazonaws.com","kushwah_1","123456789","newdb",0,NULL,0);
        if(conn){
                query="SELECT * FROM availableequipments WHERE EQUIPMENT_CATEGORY='"+equipment+"'";
                q=query.c_str();
                qstate=mysql_query(conn,q );
                     if(!qstate){
                            res=mysql_store_result(conn);

                            int x=mysql_num_rows(res);
                            mysql_close(conn);
                            return x;
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

void AvailableEquipments::addToAvailableData(vector<string> equipments, vector<string> equipmentId) {
    MYSQL * conn;
    MYSQL_RES* res;
    MYSQL_ROW row;
    int qstate;
    string query;
    const char* q;
    conn=mysql_init(0);
     conn=mysql_real_connect(conn,"mydbinstance.cs01ubstkjtv.ap-south-1.rds.amazonaws.com","kushwah_1","123456789","newdb",0,NULL,0);
        if(conn){
                for(int i=0;i<equipmentId.size();i++){
                    query="INSERT INTO availableequipments (EQUIPMENT_CATEGORY,EQUIPMENT_ID) VALUES ( '"+equipments[i]+"','"+equipmentId[i]+"')";
                    q=query.c_str();
                    qstate=mysql_query(conn,q );
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

void AvailableEquipments::addEquipment(string equipment, vector<string> equipmentId) {
    MYSQL * conn;
    MYSQL_RES* res;
    MYSQL_ROW row;
    int qstate;
    string query;
    const char* q;
    conn=mysql_init(0);
     conn=mysql_real_connect(conn,"mydbinstance.cs01ubstkjtv.ap-south-1.rds.amazonaws.com","kushwah_1","123456789","newdb",0,NULL,0);
        if(conn){
                for(int i=0;i<equipmentId.size();i++){
                    query="INSERT INTO availableequipments (EQUIPMENT_CATEGORY,EQUIPMENT_ID) VALUES ( '"+equipment+"','"+equipmentId[i]+"')";
                    q=query.c_str();
                    qstate=mysql_query(conn,q );
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

void AvailableEquipments::getCompleteList(vector<string> &equipmentCategory, vector<int> &equipmentCount) {
    MYSQL * conn;
    MYSQL_RES* res;
    MYSQL_ROW row;
    int qstate;
    string query;
    const char* q;
    conn=mysql_init(0);
     conn=mysql_real_connect(conn,"mydbinstance.cs01ubstkjtv.ap-south-1.rds.amazonaws.com","kushwah_1","123456789","newdb",0,NULL,0);
            if(conn){
                    query="SELECT * FROM availableequipments";

                    q=query.c_str();
                    qstate=mysql_query(conn,q );
                       if(!qstate){
                                res=mysql_store_result(conn);

                                map<string,int> mp;
                                map<string,int> :: iterator it;
                                int x=mysql_num_rows(res);
                                while(x>0){
                                    row=mysql_fetch_row(res);
                                    mp[row[0]]++;
                                    x--;
                                }

                                it=mp.begin();

                                for(it=mp.begin();it!=mp.end();it++){
                                    equipmentCategory.push_back(it->first);
                                    equipmentCount.push_back(it->second);
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

string AvailableEquipments::getId(string equipment) {
    MYSQL * conn;
    MYSQL_RES* res;
    MYSQL_ROW row;
    int qstate;
    string query;
    const char* q;
    conn=mysql_init(0);
     conn=mysql_real_connect(conn,"mydbinstance.cs01ubstkjtv.ap-south-1.rds.amazonaws.com","kushwah_1","123456789","newdb",0,NULL,0);
        if(conn){
                query="SELECT * FROM availableequipments WHERE EQUIPMENT_CATEGORY='"+equipment+"'";
                q=query.c_str();
                qstate=mysql_query(conn,q );
                    if(!qstate){
                            res=mysql_store_result(conn);
                            if(mysql_num_rows(res)>0){
                                row=mysql_fetch_row(res);
                                string x=row[1];
                                mysql_close(conn);
                                return x;
                            }
                    }
                    else{
                        cout<<"\n"<<mysql_error(conn)<<"\n";
                        return NULL;
                    }
        }
        else{
            cout<<"\n"<<mysql_error(conn)<<"\n";
            return NULL;
        }
}
