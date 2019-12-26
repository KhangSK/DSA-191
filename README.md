# DSA191-Assignment 1: Transportation System

## 1. Introduction
Transportation system is always a concern wherever you go. 
It is a complicated system with various subsystems, sometimes does not connect. 
Building applications that help people find the optimal route for traveling is 
an important task in a smart city. In this assignment, the student will build 
an application to manage the subway system of the cities.

The student should perform a deep analysis of problem requirements before 
implementing. Also, the student is encouraged to follow the problem-solving 
process to do well in the assignment. In this assignment, the student must 
design the data structure and utilize them in the project with the highest 
performance. The linked list is the target data structure in this assignment. 
The student must implement the required features using only this data structure 
with no additional libraries. All required libraries have been included in the 
initial code. The detailed requirements are given in the next section.

## 2. Requirements
### 2.1. Dataset
Students have access to a simple dataset of stations of the subways system 
of big cities in the world. The dataset includes several tables in the form 
of CSV files: ``cites.csv``, ``station_lines.csv``, ``stations.csv``, 
``systems.csv``, ``lines.csv``, ``lines.csv``, ``track_lines.csv``, 
``tracks.csv``. This dataset (citylines.co) is open data licensed under the 
[Open Database License](http://opendatacommons.org/licenses/odbl/1.0/) (ODbL). 
Any rights in individual contents of the database are licensed under the 
[Database Contents License](http://opendatacommons.org/licenses/dbcl/1.0/) (DbCL).

#### cities.csv
Cities.csv includes coordinates, start year, and other geographic information. 
This table has the following columns: 
    
    - id: integer
	- name: string
	- coords: string
	- start_year: integer
	- url_name: string
	- country: string
	- country_state: string

The student should define the data structure according to the description above. 
You can ignore some information if they are unnecessary for processing requests.

#### lines.csv
``Lines.csv`` includes coordinates, start year, and other geographic information.
This table has the following columns: 

	- id: integer
	- city_id: integer
	- name: string
	- url_name: string
	- color: string
	- system_id: integer
	- transport_mode_id: integer

#### station_lines.csv
``Station_lines.csv`` describes the relationship between lines and stations. 
This table has the following columns: 

	- id: integer
	- station_id: integer
	- line_id: integer
	- city_id: integer
	- created_at: date
	- updated_at: date

#### stations.csv
``Stations.csv`` describes detailed information on stations. 
This table has the following columns: 

	- id: integer
	- name: string
	- geometry: string
	- buildstart: integer
	- opening: integer
	- closure: integer
	- city_id: integer

#### systems.csv
This file contains the name of the transportation system with the following fields: 

	- id: integer
	- city_id: integer
	- name: string

Please note that some systems don't have a name, so several fields will be left empty. 
Students can decide to use this table or not.

#### tracks.csv
This table describes detailed information of tracks, including a sequence of points 
stored in ``geometry`` field. It has the following columns: 

	- id: integer
	- geometry: string
	- buildstart: integer
	- opening: integer
	- closure: integer
	- length: integer
	- city_id: integer

#### track_lines.csv
This table tells the line that each track belongs to. 
It has the following columns: 

	- id: integer
	- section_id: integer
	- line_id: integer
	- created_at: date
	- updated_at: date
	- city_id: integer
 
### 2.2. Requests
In this assignment, the application will receive a sequence of requests. 
These requests are represented in the form of input text as follows:


| Request | Output | Description | 
|:--------|:-------|-------------|
| CL | integer | Count the number of lines in the dataset.|
| CL <city_name> | integer | Count the number of lines in the given city. If the city does not exist, return -1.|
| LSC <city_name> | integer array | List stations (``station_id``) of a city (given <city\_name>). The order of stations is determined by their appearance in ``stations.csv``.|
| LLC <city_name> | integer array | List lines (``line_id``) of a city (given <city\_name>). The order of this list is given in ``lines.csv``.|
| LSL <line_id> | integer array | List stations (``station_id``) of a line with <line\_id>. The order of station is determined by its appearance in ``station_lines.csv``.|
| FC <city_name> | integer | Find a city with the given name. Return the first ``city_id`` if found, -1 otherwise.|
| FS <station_name> | integer | Find a station with the given name. Return the first ``station_id`` if found, -1 otherwise.|
| SLP <station_id> <track_id> | integer | Find the position of a station in a track. Return the index of that station if found, -1 otherwise. The order of station is determined by ``LINESTRING`` in ``tracks.csv``.|
| IS <csv_description> | integer | Insert a station into the dataset. The information of the station is given in ``csv_description``, which includes everything you see in ``stations.csv`` except the ``id`` and ``city_id``. If this operation success, we have to receive ``station id`` as the return value.  Note that we keep track the **maximum id** of every entities in the dataset so that when you insert a new instance, the allocated id should be the ``id_max + 1`` |
| RS <station_id> | integer | Remove a station from the dataset. As a consequence, every records related to the station must be removed. Return 0 if success, return -1 if the station does not exist or can not be removed.| 
| US <station_id> <csv_description> | integer | Update the information of a station with id <station_id>. Return 0 if success, and -1 otherwise.|
| ISL <station_id> <line_id> <pos> | integer | Insert a station <station_id> to a line <line_id> at index <pos>. Note that the first position has index 0. Return 0 if success, and -1 otherwise.<br> **NOTE**: The expected result of this request is that when we request LSL, the new station must stay at position <pos>. If the station exists in the line, this operation will fail and no change should be made.|
| RSL <station_id> <line_id> | integer | Remove a station <station_id> from a line <line_id>. <br>Return 0 if success, and -1 otherwise.|

The requests are given in the form of strings, and the location of the output 
is given in an input address. The student must implement the function to load 
data from the given files into the defined data structure. 

## 3. Implementation
An initial code package is provided with some source files. The ``main.cpp`` 
file contains the main function of the application and should not be modified 
since it will be overwritten during the grading process. Two files 
``processData.cpp`` and ``processData.h`` will be used for implementing features 
for this program. The data structure should be defined and implemented in 
``dsalib.h``, ``dbLib.h`` and ``dblib.cpp``. 
The implemented methods in these files must remain intact since it can affect the framework operations. 
Students can implement, update, and add more members and methods for their data structure.

## 4. Regulation

### 4.1. Evaluation
The program output will be compared with the expected output from the solution. 
A test case passes if everything in the program output matches to the solution. 
The test case will fail if the program runs too slow (timeout error). This issue 
should not occur in this assignment but the student must be aware.

### 4.2. Submission
The student should follow the submission instruction on the course site (e-learning site).
One file **src.zip** contains ``processData.cpp``, ``processData.h``, 
``dsalib.h``, ``dbLib.h``, and ``dblib.cpp`` must be submitted during the given timeline. 
The OS system that builds and run code is Linux (Ubuntu). Please do not
use any special function that does not exist on Linux, otherwise, 
your code cannot be built.
Student can build their code on Linux before submit to ensure that the code works.

The deadline for this assignment is **23-09-2019**. The grading system 
will open at the deadline.

## 4.3. Ethic code
The student must perform this assignment themselves. 
Copying code is **strictly prohibited** and be considered as an ethic code violation. 
In such a case, the course result will be zero regardless of the upcoming assignments.
Please protect your code carefully. Student can help their friends by 
*giving advise, not code*.


