# DNA_RNG


This is a simple DNA generator. It uses random numbers to create encoded DNA and then stores the values in a double-linked list. This method is more efficient for storing DNA values than just using char variables and can hold more then just array I have 6 bytes per 15 links.

Planned things to add include function markers to detect different things that the DNA is creating, a parallel linked list to help with climbing and descending the linked list, and storing artifacts that the DNA has created. Additionally, I plan on making it catch the artifacts that it has created.

I plan to add seeds so that the RNG so it can be seed-based. I think this will be interesting to see how many artifacts are produced that match DNA that has been cataloged for other animals.

File streaming to stream in and stream out DNA and artifacts.

Memory allocation to set the amount of DNA and memory that the user would like.

Stretch goals:

    GUI
    Cross-check with the Human Genome Project

Some bugs: I had to wrap my functions in a struct in a function header; otherwise, it could not resolve the function call. I have no idea why, but I plan on fixing that soon, although it's low prio, I am only using function for formating numbers.
