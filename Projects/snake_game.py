# we make use of 3 libraries:
# 1.turtle->useful for graphics
# 2.random
# 3.time

import turtle
import random
import time

delay=0.1
score=0;
highest=0;

#snakebody

#getting screen using turtle 
s=turtles.Screen()
s=title("Snake game")
s.bgcolor("green")
s.setup(width=600,height=600)

#create snake head
head=turtle.Turtle()
head.speed(0)
head.shape("circle")
head.color("white")
head.fillcolor("red")
head.penup()
head.goto(0,0)
head.direction="stop"

#make food
food=turtle.Turtle()
food.speed(0)
food.shape("square")
food.color("yellow")
food.fillcolor("green")
food.penup()
foodfood.goto(0,300)
food.st() #show turtle


#score board
sb=turtle.Turtle()
sb.shape("square")
sb.fillcolor("black")
sb.penup()
sb.ht()
sb.goto(-250,-250)
sb.write("score:0         |     Heighest score: 0")

def moveup():
    if head.direction!="down":
        head.direction="up"
def movedown():
    if head.direction!="up":
        head.direction="down"
def moveright():
    if head.direction!="left":
        head.direction="right"
def moveleft():
    if head.direction!="right":
        head.direction="left"
def movestop():
    head.direction="stop"

def move():
    if head.direction=="up":
        y=head.ycor()
        head.sety(y+20)
    if head.direction=="down":
        y=head.ycor()
        head.sety(y-20)
    if head.direction=="left":
        x=head.xcor()
        head.setx(x+20)  
    if head.direction=="right":
        x=head.xxor()
        head.setx(x-20)


#event handling --by keyboard keys

s.listen()
s.onkey(moveup,"Up")
s.onkey(movedown,"Down")
s.onkey(moveleft,"Left")
s.onkey(moveright,"Right")
s.onkey(movetop,"space")

#main loop

while True:
    s.update() #for screen updation time to time

    #check collision with wall and change x and y values there
    if head.xcor()>290:
        head.setx(-290)
    if head.xcor()>-290:
        head.setx(290)
    if head.ycor()>290:
        head.sety(-290)
    if head.ycor()>-290:
        head.sety(290)
    


    #check collision with food
    if head.distance(food)<20:


        #first change would be to relocate the food
        x=random.randint(-290,290)
        y=random.randint(-290,290)
        food.goto(x,y)

        #now increase the length of the snake
        body=turtle.Turtle()
        body.speed(0)
        body.penup()
        body.shape("circle")
        body.fillcolor("black")
        bodies.append(body)

        #increase the score
        score+=10

        #change delay and increase speed as game is progressing
        delay-=0.002

        #update the highest score here
        if score>highest:
            highest=score
        sb.clear()
        sb.write("Score: () heighest score: ()".format(score,highest))


        #move the snake bodies
        for index in range(len(bodies)-1,0,-1):
            x=bodies[index-1].xcor()
            y=bodies[index-1].ycor()
            bodies[index].goto(x,y)

        if len(bodies)>0:
            x=head.xcor()
            y=head.ycor()
            bodies[0].goto(x,y)

        move()


    
    #to check if there is collision with snake's body

    for body in bodies:
        if body.distance(head)<20:
            time.sleep(1)
            head.goto(0,0)
            head.direction="stop"


            #hide bodies

            for body in bodies:
                body.ht()
            bodies.clear()


            score=0
            delay=0.1

            #update score board
            sb.clear()
            sb.write("score:()  highest score:()".format(score,highest))
        time.sleep(delay)
s.mainloop()
