COUNT=100
DB=postgres
USER=postgres
HOST=localhost
PASSWORD=

build: create_tables populate

help :
	@echo "Usage: make [target]"
	@echo "valid targets are:"
	@echo -e "\thelp - for this message"
	@echo -e "\tcreate_tables - for create tables"
	@echo -e "\tclean - for delete tables"
	@echo -e "\trebuild - clear then create_tables"

create_tables : 
	psql -f tables.sql $(DB) $(USER) --host=$(HOST)

.PHONY : populate
populate :  
	cd populate && \
	perl populate.pl $(COUNT) $(DB) $(USER) $(HOST) $(PASSWORD)

clean : 
	psql -f clear.sql $(DB) $(USER) --host=$(HOST) 2> /dev/null 

rebuild : clean create_tables populate
