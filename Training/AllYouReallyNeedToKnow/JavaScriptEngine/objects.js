export function instance() {
    var myObject = new MyInvocableObject();
    myObject.variable4 = 24;
    myObject.variable5 = 42;
    myObject.variable6 = "Don't panic";

    myObject.testPrint();
    return "Returning from script";
}
