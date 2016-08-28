namespace A {
    int i;
    namespace B {
        int i;  // hides A::i within B
        int j;
        int f1()
        {
            int j;  // j is local to f1 and hides A::B::j
            return i;   // returns B::i
        }
    }   // namespace B is closed and names in it are no longer visible
    int f2() {
        return j;   // error: j is not defined
    }
    int j = i;  // initialized from A::i
}