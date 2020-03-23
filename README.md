# traffic-management-hardware
THIS IS A PROJECT WHICH IS TARGETED TOWARDS CONTROLLING THE TRAFFIC
This project is built up on the basis of a few aspects , they are : 
1.lane assist management : this is based on continuity principle where we have made the use of linkledist where the nodes being the street lights and we take the widths of node 1 as input and compare it that whether the no of cars passing at fixed span of time through node 1(q1)
is equal to the cars passing at node 2(q2)
2. speed assistance using PIR sensor 
3. car queue management using the data structure queue.
4 .parking assist : in our projects we have limited the parking spots to 6 as its a prototype but out motive was to use infrared  or ultrasonic sensors embedded in the ground so when the cars are over it the waves sent by the receiver can be absorbed by the emitter .and when not i.e the parking slot is empty , the receiver doesnt receive the wave sent out then by geofencing we would send messages to the dashboard of the cars within a radii of 5 km , we would do this by linking our API with companies own softwares like nissan connect and hyundai blue link . 
