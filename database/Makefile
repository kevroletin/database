DB=postgres
DBUSER=postgres

build: create_tables populate

help :
	@echo "Usage: make [target]"
	@echo "valid targets are:"
	@echo -e "\thelp - for this message"
	@echo -e "\tcreate_tables - for create tables"
	@echo -e "\tclear - for delete tables"
	@echo -e "\trebuild - clear then create_tables"

create_tables : 
	psql -f tables.sql $(DB) $(DBUSER)

populate : cars passports customers

cars :
	psql -f populate/cars.sql $(DB) $(DBUSER)

customers :
	psql -f populate/customers.sql $(DB) $(DBUSER)	

passports :
	psql -f populate/passports.sql $(DB) $(DBUSER)	

clear : 
	psql -f clear.sql $(DB) $(DBUSER) 2> /dev/null 

rebuild : clear create_tables populate
