
#include <iostream>
#include "clsDate.h";
#include "clsPeriod.h"


using namespace std;

int main()
{
   /*clsDate Date1;
    Date1.Print();
   
    clsDate Date2(7,2,2026);
    Date2.Print();
*/


    clsPeriod Period1(clsDate(1, 1, 2026), clsDate(10, 1, 2026));
    Period1.Print();

    cout << "\n";

    clsPeriod Period2(clsDate(9, 1, 2026), clsDate(12, 1, 2026));
    Period2.Print();


    //You can check like this
    cout << Period1.IsOverLapWith(Period2) << endl;


    //Also you can call the static method and send period 1 and period 2
    cout << clsPeriod::IsOverlapPeriods(Period1, Period2) << endl;



   /* clsDate Date2("12/2/2026");
    Date2.Print();
   

    clsDate Date3(12,2,2026);
    Date3.Print();

    clsDate Date4(200,2026);
    Date4.Print();*/

    
    return 0;
}

