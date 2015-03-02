<?php

/**
 * @file
 *
 * Plugin to provide a profile2_edit_form context
 *
 * @thanks to : http://internetdevels.com/blog/ctools-context-plugin
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t("Profile2 edit form by Niels"),
  'description' => t('A profile2 edit form.'),
  'context' => 'profile2_panels_context_create_profile2_edit_form',
  'edit form' => 'profile2_panels_context_profile2_edit_form_settings_form',
  'defaults' => array('pid' => ''),
  'keyword' => 'profile2_edit',
  'context name' => 'profile2_edit_form',
  'convert list' => 'profile2_panels_context_profile2_edit_convert_list',
  'convert' => 'profile2_panels_context_profile2_edit_convert',
  'placeholder form' => array(
    '#type' => 'textfield',
    '#description' => t('Enter the PID of a Profile2 for this argument:'),
  ),
);

/**
 * It's important to remember that $conf is optional here, because contexts
 * are not always created from the UI.
 */
function profile2_panels_context_create_profile2_edit_form($empty, $profile2 = NULL, $conf = FALSE) {

  // We want to create the taxonomy add form, so we need to add the form contexts too.
  $context = new ctools_context(array(
    'form',
    'profile2_edit_form',
  ));
  $context->keyword = 'profile2_edit';
  $context->plugin = 'profile2_edit_form';

  if ($empty) {
    return $context;
  }


  // Build default output.
  module_load_include('inc', 'profile2_page', 'profile2_page');

  $form = entity_ui_get_form('profile2', $profile2);
  $context->form = $form;
  $context->form_id = $form['#form_id'];
  // Empty form_title (otherwise will produce error).
  $context->form_title = "";
  $context->data = $profile2;

  return $context;
}

function profile2_panels_context_profile2_edit_form_settings_form($form, &$form_state) {
  $conf = &$form_state['conf'];

  $form['profile2'] = array(
    '#title' => t('Profile2'),
    '#type' => 'textfield',
    '#maxlength' => 512,
    '#autocomplete_path' => 'ctools/autocomplete/profile2',
    '#weight' => -10,
  );

  return $form;
}

function profile2_panels_context_profile2_edit_form_settings_form_submit($form, &$form_state) {
  $form_state['conf']['profile2'] = $form_state['values']['profile2'];
}

/**
 * Provide a list of ways that this context can be converted to a string.
 */
function profile2_panels_context_profile2_edit_convert_list() {
  // Pass through to the "profile" context convert list.
  $plugin = ctools_get_context('profile2');
  return ctools_context_entity_convert_list($plugin);
}

/**
 * Convert a context into a string.
 */
function profile2_panels_context_profile2_edit_convert($context, $type) {
  if ($type == 'profile2') {
    return $context->data['profile2'];
  }
  // Pass through to the "profile" context convert list.
  $plugin = ctools_get_context('profile2');
  return ctools_context_entity_convert($context, $type);
}
