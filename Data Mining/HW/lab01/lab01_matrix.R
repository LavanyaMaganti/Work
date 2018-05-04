mat <- matrix(c(1:4),2,2,,byrow=TRUE)
print(mat)
mat[1,1]<- 4
print(mat)
print(solve(mat))
