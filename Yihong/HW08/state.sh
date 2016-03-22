while true;
do
vmstat | tee -a state
sleep 0.2
done
