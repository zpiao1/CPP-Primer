namespace blip {
    int i = 16, j = 15, k = 23;
    // other declarations
}
int j = 0;  // ok: j inside blip is hidden inside a namespace
void manip()
{
    // using directive; the namespace in blip are "added" to the global scope
    using namespace blip;   // clash between ::j and blip::j
    // detected only if j is used
    ++i;    // sets blip::i to 17
    ++j;    // error ambiguous: global j or blip::j?
    ++::j;  // ok: sets global j to 1
    ++blip::j;  // ok: sets blip::j to 16
    int k = 97; // local k hides blip::k
    ++k;    // sets local k to 98
}