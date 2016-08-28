class ZooAnimal;
class Bear;
class Character { /* ... */ };
class BookCharacter : public Character { /* ... */ };
class ToyAnimal { /* ... */ };
class TeddyBear : public BookCharacter, public Bear, public virtual ToyAnimal 
{ /* ... */ };
// Construction order for TeddyBear:
// ZooAnimal();    // Bear's virtual base class
// ToyAnimal();    // direct virtual base class
// Character();    // indirect base class of first nonvirtual base class
// BookCharacter();    // first direct nonvirtual base class
// Bear(); // second direct nonvirtual base class
// TeddyBear();    // most derived class