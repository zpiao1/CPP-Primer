#include <exception>
#include <stdexcept>
using namespace std;
int main()
{
    catch (my_error &eObj) {    // specifier is a reference type
        eObj.status = errCodes::severeErr;  // modifies the exception object
        throw;
    } catch (other_error eObj) {    // specifier is a nonreference type
        eObj.status = errCodes::badErr; // modifies the local copy only
        throw;  // the status member of the exception object is unchanged
    }
    return 0;
}