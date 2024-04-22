# EV Charging Station Analysis

## About the Project

### Author Information
- **Full Name**: Abhishek Birajdar
- **Username**: acbirajdar
- **Course**: CSCI 211 Programming and Algorithms II, Spring 2024

### Project Overview
This project is dedicated to analyzing the growth and distribution of Electric Vehicle (EV) charging stations across various regions. It utilizes basic data structures to manage and process data effectively, aiming to provide insights into the availability and development of EV infrastructure.

### Research Question
How has the distribution and availability of EV charging stations, especially those equipped with DC Fast charging capabilities, evolved over recent years across different states?

### Stakeholders
- **Policy Makers and Urban Planners**: Can leverage this data to plan and allocate resources effectively.
- **EV Manufacturers**: To understand market penetration and infrastructure support.
- **Environmental Advocates**: To promote sustainable transportation solutions.
- **General Public and EV Users**: To better understand EV charging accessibility.

### Problem-Solving Approach
- **Variables/Inputs**: Data includes city, state, ZIP code, and number of fast chargers.
- **ADT Choice**: Utilized a Binary Search Tree (BST) for efficient data retrieval based on geographical locations and a Linked List for managing sequential data entries. These structures support quick searches and easy data management.

## Directory Structure
- **src/**: Contains source code files.
  - `main.cpp`: The main driver of the program.
  - `StationList.cpp`: Manages a list of all stations.
  - `EVStationTree.cpp`: Facilitates efficient geographical searches.
  - `StationData.h`: Definitions of the station structure.
  - `StationList.h`: Linked list structure for station data.
  - `EVStationTree.h`: Binary search tree structure.
- **data/**: Contains the CSV data file `EV_Charging_Data.csv`.
- **docs/**: Documentation related to the project.


## Usage

### Compiling the Program
This project includes a Makefile for easy compilation. To compile the project, navigate to the project directory and run:
```bash
make
