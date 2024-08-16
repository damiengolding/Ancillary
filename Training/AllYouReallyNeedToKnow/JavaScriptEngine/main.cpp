/*
MIT License

Copyright (c) Damien Golding 2024

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#include <QCoreApplication>
#include <QJSEngine>
#include <QDebug>
#include <QRandomGenerator>

#include "simplejsobject.hpp"
#include "invocablejsobject.hpp"

void testJavaScript();

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    testJavaScript();

    return(0);
}

void testJavaScript(){
    QJSEngine engine;
    QJSValueList args;
#pragma Built-in evaluations {

    /*
        --- Simple evaluation ---
    */

    QJSValue ret1;
    ret1 = engine.evaluate("2 + 2");
    qInfo() << "Evaluate addition: " << ret1.toInt();

    /*
        --- Creating and calling a simple function ---
    */

    // args << 3 << 3;
    // QJSValue mult = engine.evaluate("(function(a,b) { return a * b; })");
    // QJSValue ret2 = mult.call(args);
    // qInfo() << "Evaluate multiplication: " << ret2.toInt();

    // args.clear();
    // args << 16;
    // QJSValue pwr = engine.evaluate("(function(a) { Math.pow(2, a); })");
    // QJSValue ret5 = pwr.call(args);
    // qInfo() << "Evaluate pwr: " << ret5.toInt();

    /*
        --- Adding extensions ---
    */

    engine.installExtensions( QJSEngine::ConsoleExtension | QJSEngine::GarbageCollectionExtension );
    // args.clear();
    // args << "Hello world";
    // QJSValue print = engine.evaluate("(function(a){ console.log(a); })");
    // QJSValue ret3 = print.call(args);

    /*
        --- Arrays ---
    */

    // int arrayReserve = 5;
    // QJSValue array = engine.newArray(arrayReserve);
    // for( int i = 0; i < arrayReserve; ++i ){
    //     array.setProperty(i, QRandomGenerator::global()->bounded(100) );
    // }

    // args.clear();
    // args << array;
    // QJSValue arrayIter = engine.evaluate("(function(a){"
    //                                      "for (let i = 0; i < a.length; i++) {"
    //                                      "console.log( \"Number is: \" + a[i]);"
    //                                      "}"
    //                                      "})");
    // QJSValue ret4 = arrayIter.call(args);

    /*
        --- Complex functions ---
    */

    // QJSValue power = engine.evaluate("(function(a, b) {"
    //     "let ret = 1;"
    //     "for(  var i = 0; i < b ; i++){"
    //         "ret = ret * a;"
    // "}"
    // "return ret;"
    // "})");
    // args.clear();
    // args << 2 << 16;
    // QJSValue ret6 = power.call(args);
    // qInfo() << "Evaluate power: " << ret6.toInt();

#pragma Built-in evaluations }

#pragma Script file evaluations {
    // args.clear();
    // args << 2 << 16;
    // QJSValue functionsModule = engine.importModule("./functions.js");
    // QJSValue powerFunction = functionsModule.property("power");
    // QJSValue ret7 = powerFunction.call(args);
    // qInfo() << "Evaluate power from script: " << ret7.toInt();

#pragma Script file evaluations }

#pragma QObject integration - simple {
    // SimpleJSObject* simpleJSObject = new SimpleJSObject();
    // QJSValue sObj = engine.newQObject(simpleJSObject);
    // engine.setObjectOwnership(simpleJSObject, QJSEngine::CppOwnership);

    // engine.globalObject().setProperty("simpleobject", sObj);
    // engine.evaluate("simpleobject.variable1 = 3");
    // engine.evaluate("simpleobject.variable2 = 7");
    // engine.evaluate("simpleobject.variable3 = \"Hello from C++\"");
    // QJSValue ret8 = sObj.property("testPrint").call();

#pragma QObject integration  - simple }

#pragma QObject integration - invocable {
    QJSValue jsMetaObject = engine.newQMetaObject(&InvocableJSObject::staticMetaObject);
    engine.globalObject().setProperty("MyInvocableObject", jsMetaObject);

    // From C++
    // engine.evaluate("var myObject = new MyInvocableObject()");

    // From script
    // QJSValue objectsModule = engine.importModule("./objects.js");
    // QJSValue instanceFunction = objectsModule.property("instance");
    // QJSValue ret9 = instanceFunction.call();
    // qInfo() << "Evaluate instance from script: " << ret9.toString();

#pragma QObject integration - invocable }

}
