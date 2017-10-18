transcript on
if {[file exists rtl_work]} {
	vdel -lib rtl_work -all
}
vlib rtl_work
vmap work rtl_work

vlog -vlog01compat -work work +incdir+/home/morales/Documentos/Git/tucanOS/hard_drive {/home/morales/Documentos/Git/tucanOS/hard_drive/harddrive.v}

