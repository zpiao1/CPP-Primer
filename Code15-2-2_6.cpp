class NoDerived final { /*  */ };   // NoDerived can't be a base class
class Base { /*  */ };
// Last is final; we cannot inherit from Last
class Last final: Base { /*  */ };  // Last can't be a base class
class Bad: NoDerived { /*  */ };    // error: NoDerived is final
class Bad2: Last { /*  */ };        // error: Last is final