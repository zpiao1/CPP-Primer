#include <string>
#include <memory>
int main()
{
    // transfers ownership from p1 (which points to the string Stegosaurus) to p2
    unique_ptr<string> p2(p1.release());    // release makes p1 null
    unique_ptr<string> p3(new string("Trex"));
    // transfers ownership from p3 to p2
    p2.reset(p3.release()); // reset deletes the memory to which p2 had pointed
    p2.release();   // WRONG: p2 won't free memory and we've lost the pointer
    auto p = p2.release();  // ok, but we must remember to delete(p)
    return 0;
}