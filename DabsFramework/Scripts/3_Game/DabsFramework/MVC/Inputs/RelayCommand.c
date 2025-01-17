// Abstract Class
class RelayCommand
{
	protected bool m_CanExecute = true;

	protected ViewController m_Controller;
	void SetController(ViewController controller)
	{
		m_Controller = controller;
	}

	protected ViewBinding m_ViewBinding;
	void SetViewBinding(ViewBinding view_binding)
	{
		m_ViewBinding = view_binding;
	}

	// returns bool defining whether or not the Execute can be called
	bool CanExecute()
	{
		return m_CanExecute;
	}

	// sets whether or not RelayCommand can be executed
	// depreciate if BI ever adds property Getters and Setters
	void SetCanExecute(bool state)
	{
		m_CanExecute = state;
		thread CanExecuteChanged(m_CanExecute);
	}

	/* Abstract Methods */

	// called when type is Clicked, Selected, or Changed
	// Return: Handled (if false, will continue to execute up the tree)
	bool Execute(Class sender, CommandArgs args);

	// Abstract function called when execution ability is changed
	void CanExecuteChanged(bool state);
}