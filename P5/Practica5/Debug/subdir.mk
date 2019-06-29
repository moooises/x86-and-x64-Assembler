################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../main.c \
../qdbmp.c 

S_UPPER_SRCS += \
../sse_imagen_a_blanco_y_negro.S \
../sse_producto_escalar.S \
../sse_sumar_filas.S 

OBJS += \
./main.o \
./qdbmp.o \
./sse_imagen_a_blanco_y_negro.o \
./sse_producto_escalar.o \
./sse_sumar_filas.o 

C_DEPS += \
./main.d \
./qdbmp.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

%.o: ../%.S
	@echo 'Building file: $<'
	@echo 'Invoking: GCC Assembler'
	nasm -f elf64 -g -F dwarf -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


