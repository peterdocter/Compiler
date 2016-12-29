import os
import re

regs=['t1','t2','t3','t4','t5','t6','t7','t8','t9','s0','s1','s2','s3','s4','s5','s6','s7']
table={}
reg_ok={}
variables=[]

def load_variables(inter_code):
    global variables
    temp_re='(temp\d+)'
    for line in inter_code:
        temps=re.findall(temp_re,' '.join(line))
        variables+=temps

def load_inter_code(filename):
    lines=[]
    for line in open(filename,'r',encoding='utf-8'):
        line=line.replace('\r','').replace('\n','')
        if line =='':
            continue
        lines.append(line.split(' '))
    return lines

def get_reg(string):
    try:
        variables.remove(string)
    except:
        pass
    if string in table:
        return '$'+table[string]
    else:
        keys=[]
        for key in table:
            keys.append(key)
        for key in keys:
            if 'temp' in  key and key not in variables:
                reg_ok[table[key]]=1
                del table[key]
        for reg in regs:
            if reg_ok[reg]==1:
                table[string]=reg
                reg_ok[reg]=0
                return '$'+reg

def translate(line):
    if line[0]=='LABEL':
        return line[1]+':'
    if line[1]==':=':
        if len(line)==3:
            if line[-1][0]=='#':
                return '\tli %s,%s'%(get_reg(line[0]),line[-1].replace('#',''))
            else:
                return '\tmove %s,%s'%(get_reg(line[0]),get_reg(line[2]))
        if len(line)==5:
            if line[3]=='+':
                if line[-1][0]=='#':
                    return '\taddi %s,%s,%s'%(get_reg(line[0]),get_reg(line[2]),line[-1].replace('#',''))
                else:
                    return '\tadd %s,%s,%s'%(get_reg(line[0]),get_reg(line[2]),get_reg(line[-1]))
            elif line[3]=='-':
                if line[-1][0]=='#':
                    return '\taddi %s,%s,-%s'%(get_reg(line[0]),get_reg(line[2]),line[-1].replace('#',''))
                else:
                    return '\tsub %s,%s,%s'%(get_reg(line[0]),get_reg(line[2]),get_reg(line[-1]))
            elif line[3]=='*':
                return '\tmul %s,%s,%s'%(get_reg(line[0]),get_reg(line[2]),get_reg(line[-1]))
            elif line[3]=='/':
                return '\tdiv %s,%s\n\tmflo %s'%(get_reg(line[2]),get_reg(line[-1]),get_reg(line[0]))
        if line[2]=='CALL':
            if line[3]=='read' or line[3]=='write':
                return '\taddi $sp,$sp,-4\n\tsw $ra,0($sp)\n\tjal %s\n\tlw $ra,0($sp)\n\tmove %s,$v0\n\taddi $sp,$sp,4'%(line[-1],get_reg(line[0]))
            else:
                return '\taddi $sp,$sp,-8\n\tsw $t0,0($sp)\n\tsw $ra,4($sp)\n\tjal %s\n\tlw $a0,0($sp)\n\tlw $ra,4($sp)\n\taddi $sp,$sp,8\n\tmove %s $v0'%(line[-1],get_reg(line[0]))
    if line[0]=='GOTO':
        return '\tj %s'%line[1]
    if line[0]=='RETURN':
            return '\tmove $v0,%s\n\tjr $ra'%get_reg(line[1])
    if line[0]=='IF':
        if line[2]=='==':
            return '\tbeq %s,%s,%s'%(get_reg(line[1]),get_reg(line[3]),line[-1])
        if line[2]=='!=':
            return '\tbne %s,%s,%s'%(get_reg(line[1]),get_reg(line[3]),line[-1])
        if line[2]=='>':
            return '\tbgt %s,%s,%s'%(get_reg(line[1]),get_reg(line[3]),line[-1])
        if line[2]=='<':
            return '\tblt %s,%s,%s'%(get_reg(line[1]),get_reg(line[3]),line[-1])
        if line[2]=='>=':
            return '\tbge %s,%s,%s'%(get_reg(line[1]),get_reg(line[3]),line[-1])
        if line[2]=='<=':
            return '\tble %s,%s,%s'%(get_reg(line[1]),get_reg(line[3]),line[-1])
    if line[0]=='FUNCTION':
        return '%s:'%line[1]
    if line[0]=='CALL':
        if line[-1]=='read' or line[-1]=='write':
            return '\taddi $sp,$sp,-4\n\tsw $ra,0($sp)\n\tjal %s\n\tlw $ra,0($sp)\n\taddi $sp,$sp,4'%(line[-1])
        else:
            return '\taddi $sp,$sp,-8\n\tsw $t0,0($sp)\n\tsw $ra,4($sp)\n\tjal %s\n\tlw $a0,0($sp)\n\tlw $ra,4($sp)\n\taddi $sp,$sp,8'%(line[-1])
    if line[0]=='ARG':
        return '\tmove $t0,$a0\n\tmove $a0,%s'%get_reg(line[-1])
    if line[0]=='PARAM':
        table[line[-1]]='a0'
    return ''

def write_to_txt(obj_code):
    f=open('result.asm','w')
    template='''
.data
_prompt: .asciiz "Enter an integer:"
_ret: .asciiz "\\n"
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
'''
    f.write(template)
    for line in obj_code:
        f.write(line+'\n')
    f.close()

def parser():
    for reg in regs:
        reg_ok[reg]=1
    inter_code=load_inter_code('output_1.txt')
    load_variables(inter_code)
    obj_code=[]
    for line in inter_code:
        obj_line=translate(line)
        if obj_line=='':
            continue
        obj_code.append(obj_line)
    write_to_txt(obj_code)

parser()
