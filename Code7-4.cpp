Screen::pos ht = 24, wd = 80;   // use the pos type defined by Screen
Screen scr(ht, wd, ' ');
Screen *p = &scr;
char c = scr.get(); // fetches the get member from the object scr
c = p->get();       // fetches the get member from the object to which p points