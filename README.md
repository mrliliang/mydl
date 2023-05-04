# mydl

The project is a prtotype Datalog engine. It supports stratified dataglog with negation and aggregation and supports aggregation in recursion. 
It implements the semi-naive evaluation algorithm. It builds on the relation database system. A Datalog program executes iteratively, this engine 
controls the iteration loop, and in each iteration each Datalog rule is translated into a SQL statement which is sent to the relation database 
system to exectue query.
