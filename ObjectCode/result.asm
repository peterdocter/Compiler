
.data
_prompt: .asciiz "Enter an integer:"
_ret: .asciiz "\n"
.globl main
.text
read:
    li $v0,4
    la $a0,_prompt
    syscall
    li $v0,5
    syscall
    jr $ra

write:
    li $v0,1
    syscall
    li $v0,4
    la $a0,_ret
    syscall
    move $v0,$0
    jr $ra
fact:
	move $t1,$a0
	li $t2,1
	beq $t1,$t2,label0
	j label1
label0:
	move $v0,$a0
	jr $ra
label1:
	addi $t3,$a0,-1
	move $t0,$a0
	move $a0,$t3
	addi $sp,$sp,-8
	sw $t0,0($sp)
	sw $ra,4($sp)
	jal fact
	lw $a0,0($sp)
	lw $ra,4($sp)
	addi $sp,$sp,8
	move $t4 $v0
	move $t5,$a0
	mul $t6,$t5,$t4
	move $v0,$t6
	jr $ra
main:
	addi $sp,$sp,-4
	sw $ra,0($sp)
	jal read
	lw $ra,0($sp)
	move $t7,$v0
	addi $sp,$sp,4
	move $t8,$t7
	move $t9,$t8
	li $s0,1
	bgt $t9,$s0,label3
	j label4
label3:
	move $s1,$t8
	move $t0,$a0
	move $a0,$s1
	addi $sp,$sp,-8
	sw $t0,0($sp)
	sw $ra,4($sp)
	jal fact
	lw $a0,0($sp)
	lw $ra,4($sp)
	addi $sp,$sp,8
	move $s2 $v0
	move $s3,$s2
	j label5
label4:
	li $s3,1
label5:
	move $s4,$s3
	move $t0,$a0
	move $a0,$s4
	addi $sp,$sp,-4
	sw $ra,0($sp)
	jal write
	lw $ra,0($sp)
	addi $sp,$sp,4
	li $s5,0
	move $v0,$s5
	jr $ra
