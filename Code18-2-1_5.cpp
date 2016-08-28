inline namespace FifthEd {
    // namespace for the code from the Primer Fifth Edition
}
namespace FifthEd {
    class Query_base { /* ... */ };
    // other Query-related declarations
}
namespace FourthEd {
    class Item_base { /* ... */ };
    class Query_base { /* ... */ };
    // other code from the Fourth Edition
}
namespace cplusplus_primer {
#include "FifthEd.h"
#include "FourthEd.h"
}