# Room

## @Entity

Represents a table within the database. Room creates a table for each class that has @Entity annotation,
the fields in the class correspond to columns in the table.
Therefore, the entity classes tend to be small model classes that don't contain any logic.

## @Dao (data access interface)

DAOs are responsible for defining the methods that access the database.
This is the place where we write our queries.

## @Database

Contains the database holder and serves as the main access point for the underlying connection to your app's data.

## Repository (Optional)

A repository class abstracts access to multiple data sources.

## ViewModel

The ViewModelIs role is to provide data to the Ul and survive configuration changes.
A ViewModel acts as a communication center between the Repository and the UI.

### Optional

Create a data package
