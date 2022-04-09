// @basics @tests @if-statements @switch-statements

// Like a for-statement, an if-statement can introduce a variable and test it. 
// A name declared in a condition is in scope on both branches of the if-statement. 
// The purpose of declaring a name in the condition of an if-statement is to keep the scope of the variable limited to improve readability and minimize errors.
void do_something(vector<int>& v)
{
    // The most common case is testing a variable against 0 (or the nullptr). To do that, simply leave out the explicit mention of the condition.
    // if (auto n = v.size()) {
    if (auto n = v.size(); n!=0) {
        // ... we get here if n!=0 ...
    }
    // ...
}

// A switch-statement tests a value against a set of constants. 
// Those constants, called case-labels, must be distinct, and if the value tested does not match any of them, the default is chosen. 
// If the value doesn't match any case-labels and no default is provided, no action is taken.
void action()
{
     while (true) {
          cout << "enter action:\n";           // request action
          string act;
          cin >> act;          // read characters into a string
          Point delta {0,0};   // Point holds an {x,y} pair

          for (char ch : act) {
               switch (ch) {
               case 'u':  // up
               case 'n':  // north
                    ++delta.y;
                    // We don't have to exit a case by returning from the function that contains its switch-statement. 
                    // Often, we just want to continue execution with the statement following the switch-statement. We can do that using a break statement.
                    break;
               case 'r':  // right
               case 'e':  // east
                    ++delta.x;
                    break;
               // ... more actions ...
               default:
                    cout << "I freeze!\n";
               }
               move(current+delta*scale);
               update_display();
          }
     }
}
