// data class

data class Person(
    val id: Int,
    val firstName: String,
    val lastName: String,
    val age: Int
)

// class

class PersonRepository {
    fun getAllData(): List<Person> {
        val persons: MutableList<Person> = mutableListOf()
        for (i in 1..20) {
            persons.add(Person(id = i, firstName = "fname$i", lastName = "lname$i", age = 10 * i))
        }
        return persons.toList()
    }
}

// composable

@Composable
fun CustomItem(person: Person) {
    Row(
        modifier = Modifier
            .background(Color.Gray)
            .padding(24.dp),
        verticalAlignment = Alignment.CenterVertically,
        horizontalArrangement = Arrangement.spacedBy(12.dp)
    ) {
        Text(text = person.firstName, color = MaterialTheme.colorScheme.onBackground)
        Text(text = person.lastName, color = MaterialTheme.colorScheme.onBackground)
        Text(text = person.age.toString(), color = MaterialTheme.colorScheme.onBackground)
        Text(text = person.id.toString(), color = MaterialTheme.colorScheme.onBackground)
    }
}

@Composable
fun MyCompose() {
    val pr = PersonRepository()
    val allPersons = pr.getAllData()

    LazyColumn(
        Modifier.fillMaxSize(),
        horizontalAlignment = Alignment.CenterHorizontally,
        verticalArrangement = Arrangement.spacedBy(16.dp)
    ) {
        itemsIndexed(
            items = allPersons,
            key = { index: Int, person: Person -> person.id }
        ) { index, person ->
            CustomItem(person = person)
        }
    }
}