import cv2
def increase_image_file_size(img,k=7):
    width=int((img.shape[1])*k)
    height=int((img.shape[0])*k)
    increase_size_img=cv2.resize(img,(width,height),interpolation=cv2.INTER_LANCZOS4)
    cv2.imshow("Output",increase_size_img )
    cv2.waitKey(500)
    cv2.destroyAllWindows()
    cv2.imwrite('resized_output_image.jpg',increase_size_img)   
    
    
def reduce_image_file_size(img,k=5):
    width=int((img.shape[1])/k)
    height=int((img.shape[0])/k)
    reduced_img=cv2.resize(img,(width,height),interpolation=cv2.INTER_LANCZOS4)
    cv2.imshow("Output", reduced_img)
    cv2.waitKey(500)
    cv2.destroyAllWindows()
    cv2.imwrite('resized_output_image.jpg', reduced_img)

    
    
    
    
    
print("set the ratio of resize image")    
k=int(input()) #set the ratio of resize image
img=cv2.imread("img.png")# you just have to give image here 
#path of image is given above your 
print("Do you want to reduced Size or Increase Size of image")
print("If you want to Reduce press :'r' or you can Increase it by : 'i' else you can press: 'n' to do nothing")
a=input()
if a=='r' :
    reduce_image_file_size(img,k)
elif a=='i' :
    increase_image_file_size(img,k)
else:
    print("Same image Return no change")
    
    
