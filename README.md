# CaféStock — Local SQL Server Setup Guide

CaféStock is an inventory management system built with **C++/CLI** and **Windows Forms** for tracking cafeteria items, users, and capacity data.  
This README explains how to set up the **local SQL Server Express** database and configure the environment file (`.env`) to run CaféStock without errors.

---

## 🧠 Requirements

Before building CaféStock, install the following tools:

### 1. Microsoft SQL Server Express (2019 or higher)
Download link:  
➡️ [https://www.microsoft.com/en-us/sql-server/sql-server-downloads](https://www.microsoft.com/en-us/sql-server/sql-server-downloads)

### 2. SQL Server Management Studio (SSMS)
Download link:  
➡️ [https://aka.ms/ssms](https://aka.ms/ssms)

### 3. Visual Studio (Community Edition or higher)
Install the **Desktop development with C++** workload.

---

## Step 1 — Start SQL Server Express

1. After installation, open **SQL Server Management Studio**.
2. Connect to your server instance:


---

## Step 2 — Create the Database
In SSMS, open a new query window and run:

```sql
CREATE DATABASE dboInventory;
GO
USE dboInventory;
```
## Step 3 - Make Tables For Items and Users
Users
```sql
CREATE TABLE dbo.Users (
    Id INT IDENTITY(1,1) PRIMARY KEY,
    username NVARCHAR(50) NOT NULL,
    password NVARCHAR(50) NOT NULL,
    datecreated DATETIME DEFAULT GETDATE()
);
GO
```
Items
```sql
CREATE TABLE dbo.tblItems (
    Item_ID INT IDENTITY(1,1) PRIMARY KEY,
    Item_Name NVARCHAR(100) NOT NULL,
    Item_Category NVARCHAR(50) NOT NULL,
    Item_Quantity INT NOT NULL,
    Date_Modified DATETIME DEFAULT GETDATE()
);
GO
```
# Step 3 Add an .env file for apikey and contents must be contain the Server Name, Database Name, User ID and Password:

Must be in this format in .env file:

"SQL_CONN=Data Source="Server Name";Initial Catalog="Database-Name";User ID="";Password="";"

Then add .env in Solution.

Output in SMSS:

Databases:
```
dboInventory
      ├── Tables
      │    ├── dbo.Users
      │    └── dbo.tblItems
```

Output in VS:

```
CafeStock/
 ├── EnvConfig.h
 ├── .env
 ├── Methods/
 ├── Pages/
 ├── CafeStock.sln
 └── .gitignore
```
