#include <iostream>
#include <cstring>
#include <string>
#include <ostream>
#include <istream>
#include <vector>
#include <fstream>

// enum class for gender
enum class Gender
{
    Male,
    Female,
    Other
};

//structure representing a person
struct Person
{
    static const size_t MAX_NAME_LENGTH = 50;

    char name[MAX_NAME_LENGTH];
    int age;
    Gender gender;
};

//function to serialize a string to an ostream
void serializeString(std::ostream& os, const char* str)
{
    os << str;
}

//function to serialize an integer to an ostream
void serializeInt(std::ostream& os, int value)
{
    os << value;
}

//function to serialize a gender enum to an ostream
void serializeGender(std::ostream& os, Gender gender)
{
    switch (gender)
    {
    case Gender::Male:
        os << "M";
        break;
    case Gender::Female:
        os << "F";
        break;
    case Gender::Other:
        os << "Other";
        break;
    }
}

//function to serialize a person object to an ostream
void serializePerson(std::ostream& os, const Person& person)
{
    serializeString(os, person.name);
    os << ",";
    serializeInt(os, person.age);
    os << ",";
    serializeGender(os, person.gender);
    os << "\n";
}

//function to deserialize a string from an istream
void deserializeString(std::istream& is, char* buffer, size_t bufferSize)
{
    is.getline(buffer, bufferSize, ',');
}

//function to deserialize an integer from an istream
int deserializeInt(std::istream& is)
{
    int value;
    is >> value;
    is.ignore(); // Ignore the comma
    return value;
}

//function to deserialize a gender enum from an istream
Gender deserializeGender(std::istream& is)
{
    std::string genderStr;
    is >> genderStr;

    if (genderStr == "M")
        return Gender::Male;
    else if (genderStr == "F")
        return Gender::Female;
    else
        return Gender::Other;
}

//function to deserialize a person object from an istream
bool deserializePerson(std::istream& is, Person& person)
{
    deserializeString(is, person.name, Person::MAX_NAME_LENGTH);

    if (is.fail())
        return false;

    person.age = deserializeInt(is);
    person.gender = deserializeGender(is);

    return true;
}

//function to serialize a vector of person objects to an ostream
void serializePeople(std::ostream& os, const std::vector<Person>& people)
{
    for (const auto& person : people)
    {
        serializePerson(os, person);
    }
}

//function to deserialize a vector of Person objects from an istream
std::vector<Person> deserializePeople(std::istream& is)
{
    std::vector<Person> people;
    Person person;

    while (deserializePerson(is, person))
    {
        people.push_back(person);
    }

    return people;
}

int main()
{
    std::ofstream outFile("people.csv");

    Person person1 = { "John Doe", 25, Gender::Male };
    Person person2 = { "Jane Smith", 30, Gender::Female };

    serializePerson(outFile, person1);
    serializePerson(outFile, person2);

    outFile.close();

    //read from the file
    std::ifstream inFile("people.csv");

    std::vector<Person> loadedPeople = deserializePeople(inFile);

    //modify data
    loadedPeople[0].age = 26;

    //serialize back to the file
    std::ofstream updatedFile("updated_people.csv");
    serializePeople(updatedFile, loadedPeople);

    return 0;
}
