# Sports Equipment Management


    This software system is designed to increase the efficiency and performance of the administration for proper allocation and management of the hostel sports equipment. This software can be used by any institute to manage the hostel sports equipment.  
 
         Administration can use the software to allocate sports equipment to students, for personal use, as well as to sports society, for any sports competition. The software will check the availability of the required sports equipment whenever any issue request is made. Software will also keep track of the number of days student is holding some particular equipment and accordingly calculate fine if any.   
 
         Student can also check the availability of the equipment and can also make a special request to the management so as to add some more equipment to the inventory. Student can submit any equipment he/she is possessing through the software, software will update the equipment availability accordingly so as to make equipment available for other students. If the equipment is found damaged than the software will keep this particular equipment in the category of damaged equipment, and concerned authority will be informed so that further action can be taken. 


Also all the issuing and submitting processes will be done under the surveillance of the security worker for the better security of equipment, so a password with be required to complete any of the above two processes to complete, which will be available with the security worker.


### Prerequisites


 * A computer with Linux Operating system.
 * An active internet connectivity.
 * cmake, make and mysqlclient library (if not available follow instructions given below to install)
 
### Installing cmake
use below given command to install cmake if not available


sudo apt-get install cmake


### Installing make
use below given command to install make if not available


sudo apt-get install make


### Installing mysqlclient library
use below given command to install mysqlclient library


sudo apt-get install libmysqlclient-dev
    
    
### Installing and running code
1. cd code
2. cmake CMakeLists.txt
3. make
4. ./sem


Note - minimum cmake version required is 3.1 , if below version is available than make changes in the CMakeLists.txt file accordingly.
Note - if directory name code is changes to something else or location is changed after running than delete CMakeCache.txt file and follow the above steps to run it successfully.


## Built With


* [AWS](https://aws.amazon.com/rds/)- Mysql Databse server
* [CLion](https://www.jetbrains.com/clion/) - Code creation and testing
* [Codeblocks](http://www.codeblocks.org) - Code creation and testing